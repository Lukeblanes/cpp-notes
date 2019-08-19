// Notes from https://www.youtube.com/watch?v=nukqC9U1Zbo
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

    a.draw(std::cout);
    b.draw(std::cout);
    c.draw(std::cout);

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