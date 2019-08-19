// Notes from https://www.youtube.com/watch?v=ftYg_Ncd-To

#include <iostream>
#include <cstdint>
#include <vector>
#include <cstring>
#include <gameobject.hpp>

void showException(std::exception& e)
{
    std::cerr << "*****************************"
              << "\n** EXCEPTION"
              << "\n**   " << e.what()
              << "\n*****************************"
              << "\n";

}

// const uint32_t size = 1000;

void game(uint32_t size)
{
    std::cout << "\n-- Start --\n";

    using vecGO = std::vector<GameObject>;

    vecGO vgo;
    vgo.reserve(size);

    GameObject g('*', 5, 7);

    // 1. modifying push_back to emplacement_back doesn't show much improvement when using callgrind
    // valgrind --tool=callgrind --dump-line=yes ./a.out 100000
    // to show where most calls come from do:
    // callgrind_annotate --auto=yes callgrind.out.32172


    for (uint32_t i = 0; i < size; ++i)
        // 1. vgo.emplace_back( g );
        // 2. vgo.emplace_back( '*', 5, 7 );
        vgo.emplace_back( );
        
    
//    for (uint32_t i = 0; i < size; ++i)
//        vgo[i].draw(std::cout);

    // even though emplace_back and push_back seem to work the same, emplace_back can be better
    // with recently created objects

    // 2. when we pass the parameters to emplace_back, the object isn't copied but created directly by the vector

    // so push_back copies the GameObject and then is created and emplace_back can pass the parameters so that it's not copied and only created.

    // emplace_back works thanks to placement new


    std::cout << "\n-- End --\n";
}

// th
uint8_t bytes[10000];

int main(int argc, char **argv)
{
    try
    {
        // game( std::atoi(argv[1]) );

        // with placement new we indicate that we will supply where the memory will be stored
        // so placement new only calls the constructor

        // the lines below causes a memory leak since the sprite delete isn't called 
        // because the GameObject destructor isn't called
        GameObject *p = new (bytes) GameObject('*', 5, 7);
        p->draw(std::cout);

        // if we try and do:
        // delete p;
        // we will call the destructor which is correct, but we will also attempt to destroy
        // memory that is part of bytes

        // by just calling the destructor, we won't attempt 
        p->~GameObject();

        // malloc has quite a bit of overhead, with placement_new we control how 
        // the memory is allocated so we can improve our code by managing manually 
        // our memory.

        // Malloc is especially bad with many small allocations.
        
    }
    catch(std::exception& e)
    {
        showException(e);
    }
    
    return 0;
}