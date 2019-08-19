// Notes from https://www.youtube.com/watch?v=DxAGfDVkgj8
#include <iostream>
#include <cstdint>
#include <vector>

const uint32_t size = 1000;

struct GameObject
{
    uint8_t bigdata[size];
};

// little trick we can use to not have to define GameObject Vectors
// useful if we're using it many times. and the 
// it's declared globally but can be declared locally.
// if it's declared locally it is destroyed when the scope is left.
using TGO= std::vector<GameObject>;

// The C way of doing it is with typedef. The equivalent would be: 
// typedef std::vector<GameObject> TGO;

// function to explore vector
void printV(const TGO& v)
{
    std::cout << &v[0] << " - "
              << v.size() << " - "
              << v.capacity() << '\n';
}

int main(int argc, char **argv)
{
    // the declaration by itself doesn't allocate memory on the heap
    TGO vgo;

    // with an argv[1] of 2, there is a vector redimension since the 
    // size increases and a copy is made.

    // 1. in first push_back, we make a vector of size 1.
    // 2. in second push_back, we create a vector of size 2,
    // 3. copy the original array, and then push_back the second element
    // 4. we delete the original size 1 vector.

    // the reason is that since initially it has reserved space for one element, 
    // when it increases, there's no way of knowing that the contiguous memory is
    // free so there's an allocation of a bigger vector that can include both elements
    // This is because the vector guarantees that memory is contiguous

    // We need to learn about another property of a vector to understand
    // the different memory increases, the capacity. 

    // there's the size which is how many elements it currently has and 
    // the capacity which is how much it can grow until it has to create a new vector.

    // when we look at how capacity increases, we see that it grows in powers of 2
    // 0 - 1 - 2- 4 - 8 - 16 - 32 - 64 - .....

    // there's a problem with this doubling of capacity. 
    // Let's say we have a vector of 1024 GameObjects, and at some point we add another GameObject, then 
    // we would allocate space for another 1024 GameObjects. We would have a capacity of 2048 GameObjects for
    // 1025 GameObjects

    // The correct approach would be to before hand know the maximum number of GameObjects to be used in our program so
    // we reserve only what we need. 
    
    // So we know our maximum is going to be 100 so we allocate it. 
    vgo.reserve(100);

    // the memory difference of using reserve or not is staggering for 100 elements.
    // Reserve       - 173,728 bytes allocated
    // Not Reserving - 328,728 bytes allocated

    // we make a last change to our print function to show the memory location of our vector
    // to make sure if a new vector is created or not. 

    // it isn't modified when we reserve and modified when we don't.
    
    for (uint16_t i = 0; i < std::atoi(argv[1]); ++i)
    {
        printV(vgo);
        vgo.push_back(GameObject());
    }

    printV(vgo);

}
