// Notes from https://www.youtube.com/watch?v=--UZQFUavDE
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

const uint32_t size = 1000;

void game()
{
    std::cout << "\n-- Start --\n";

    GameObject a('a', 1, 3);
    GameObject b('b');
    GameObject c(a);
    GameObject d('$', 5, 5);

    a.draw(std::cout);
    b.draw(std::cout);
    c.draw(std::cout);
    d.draw(std::cout);

    // at some point someone does the following
    d = b; // equivalent to d.operator=(b); 

    // we have to be wary of things like d = d

    // It seems to work correctly but it's not freeing all the memory and delete is done twice.
    // In this case, we overwrite the allocated memory when doing d = b
    // so the original sprite d is pointing to never gets freed. That's why
    // valgrind indicates there's 1 byte lost since we cant delete the sprite. 
    // When exiting the scope, there's a delete from b and then d of the same sprite
    // which the second time around is undefined behaviour.

    // We are going to create the missing assignment operator in our GameObject Class

    d.draw(std::cout);

    using vecGO = std::vector<GameObject>;

    vecGO vgo;
    vgo.reserve(100);

    // 1. this calls the copy constructor and does 60 memory allocations. 1 for constructor and 1 for copy constructor.

    // 2. we can reduce by doing the following since there's only 1 construction
    GameObject g('a');

    // We could improve it further by using emplace_back instead of push_back

    for (uint32_t i = 0; i < 30; ++i)
        // 1. vgo.push_back( GameObject('a'));

        // 2. 
        vgo.push_back( g );
    
    for (uint32_t i = 0; i < 30; ++i)
        vgo[i].draw(std::cout);
    


    std::cout << "\n-- End --\n";
}
int main(int argc, char **argv)
{
    try
    {
        game();
    }
    catch(std::exception& e)
    {
        showException(e);
    }
    
    return 0;

}