// notes from https://www.youtube.com/watch?v=rPtIb3kQKiY
#include <iostream>
#include <cstdint>

const uint32_t kvals = 14;
const uint32_t kobjs = 50000000;

// this GameObject is 64 bytes, 4 + 4*14 + 4 = 64
// Cache Lines are normally 64 bytes so it's alligned
// if we add a boolean the time of our program is increased
// because a GameObject doesn't fit in a cache line so what 
// happens is that we load the first GameObject in a cache line 
// without the bool because it doesn't fit and the bool in the next cache line
// then, when we load the next GameObject it loads it into the current cache line.

// What we get is assuming bool is 4 bytes ( it's actually a byte but we can see the offset problem sooner)
// Line 1 : GO1.id (4), GO1.values (56), GO1.total (4)
// Line 2 : GO1.test (4), GO2.id (4), GO2.values (56)
// Line 3 : GO2.total (4), GO2.test (4), GO3.id (4), GO3.values (52)
// Line 4 : GO3.values(4), GO3.total (4), GO3.test (4). GO4.id (4), GO4.values (48)

// The offset provoked from the bool makes it so that there are cases when we read in a same line, values from two 
// different GameObjects.
struct GameObject
{
    uint32_t id;
    uint32_t values[kvals];
    uint32_t total;
    // bool test;
};

GameObject *objects;
/* Initial update 
void update()
{
    for (uint32_t i = 0; i < kvals; ++i)
    {
        for (uint32_t j = 0; j < kobjs; ++j)
        {
            objects[j].total += objects[j].values[i];
        }
    }
}*/

void update()
{
    for (uint32_t j = 0; j < kobjs; ++j)
    {
        for (uint32_t i = 0; i < kvals; ++i)
        {   // In compiler-explorer, compiling with -O3 
            objects[j].total += objects[j].values[i];
        }
    }
}
// If we draw the memory layout of our objects
// that we allocate on the heap, it would be
// ||id|values[0..13]|total| |id|values[0..13]|total| |id|values[0..13]|total| |id|values[0..13]|total| .....
// So in the initial way of updating, we jump from obj to obj for every total +=, and that makes us have a ton of cache misses. 

// when we read data, it grabs the memory we're asking for but it also grabs as much of the contiguous memory as it can fit into 
// it's L1 cache (check if it's all the cache or just the line ) and if it doesn't find in the L1 memory the next read it looks 
// into the l2 cache and so on until it needs to look in the ram which is the slowest way, 
// so during our fetch if we can organize the data we need linearly we can avoid cache misses.

// So the first way of improving our update is by changing how we access the memory. We get the first GameObject add all the values 
// to total and then jump to the next GameObject. 
int main()
{
    std::cout << sizeof(bool) << std::endl;
    std::cout << sizeof(uint32_t) << std::endl;
    objects = new GameObject[kobjs];

    update();
    std::cout << "updated\n";
    delete[] objects;

    return 0;
}