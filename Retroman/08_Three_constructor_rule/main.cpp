// Notes from https://www.youtube.com/watch?v=cFyXvERLYLQ
#include <iostream>
#include <cstdint>
#include <vector>
#include <cstring>

const uint32_t size = 1000;

struct Sprite 
{
    uint8_t c = '@';

};

struct GameObject
{
    GameObject()
    {
        spr = new Sprite();
    }

    GameObject(const GameObject& g)
    {
        // Initial solution
        /* 
        for(uint32_t i = 0; i < size; ++i)
        {
            bigdata[i] = g.bigdata[i];
        }
        */

        // More straightforward solution
        memcpy(&bigdata, g.bigdata, size);


        // below is what the default copy constructor would do
        // spr = g.spr;
        if(g.spr)
            spr = new Sprite(*g.spr);

        // we have to check if g.spr is different than nullptr to not get undefined behaviour
    }

    ~GameObject()
    {
        delete spr;
    }
    uint8_t bigdata[size];
    Sprite *spr = nullptr;
};

using TGO= std::vector<GameObject>;

void printV(const TGO& v)
{
    std::cout << &v[0] << " - "
              << v.size() << " - "
              << v.capacity() << '\n';
}

int main(int argc, char **argv)
{
    TGO vgo;

    // vgo.reserve(100);

    for (uint16_t i = 0; i < std::atoi(argv[1]); ++i)
    {
        printV(vgo);

        // In this scenario where our gameobject does new, new is called once but it is destroyed twice.
        // this is because when push_back is called with GameObject(), 
        // a copy is made with the default copy constructor which copies byte by byte. So after it is copied, 
        // the original GameObject is destroyed, and then when the program ends, we try to delete an already deleted
        // GameObject, which is undefined behaviour

        // 1. A GameObject is created on the stack temporarily to pass to push_back
        // 2. Once passed, push_back calls the copy constructor to copy it and the vector stores it in the heap
        // 3. Temporary GameObject created in the stack, calls the destructor and destroys the Sprite
        // 4. When program ends, the vector destruction calls the GameObject destructor which tries to free an already freed Sprite (Undefined Behaviour)



        // GameObject - [|bigdata|spr|] / Sprite - 0xffff [|0010101|]
        // 1 - STACK    [|01010100001|0x1020|] / 0x1020 [|01000100|]
        // 2 - HEAP     [|01010100001|0x1020|] / 0x1020 [|01000100|]
        // 3 - GameObject destructor destroys Sprite at 0x1020 so the heap GameObject is currently pointing to an already destroyed Sprite
        // 3 - STACK    (freed)
        // 3 - HEAP     [|01010100001|0x1020|] / 0x1020 (deleted)
        // 4 - Error since we try to destroy already destroyed sprite

        // https://cppinsights.io/
        // this website is good to look into what the c++ compiler is doing implicitly for us. 
        // This website shows that if we don't provide our own, constructor, destructor and copy constructor, c++ will provide it's own.

        // Taking into account that c++ creates the default constructor, copy constructor, assignment operator and destructor and in
        // most cases the defaults are enough, if there is a case like this one, where we implement our own destructor, 
        // then we also have to implement our own copy constructor and assignment operator.
        // The rule of threes (from c++98 and now called the rule of five) says that if we have our own implementation for 
        // a destructor, assignment operator or copy constructor, we have to provide the implementation for all of them. 

        // So we need to implement our own copy constructor with the correct behaviour.
        vgo.push_back(GameObject());
    }

    printV(vgo);

}
