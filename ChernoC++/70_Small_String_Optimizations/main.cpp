#include <iostream>
#include <string>

// strings allocate memory so people try avoiding using strings

// short strings don't need to be allocated. 

// When we go over 15 chars, an allocation happens
void* operator new(size_t size)
{
    std::cout << "Allocating " << size << " bytes\n";
    return malloc(size);
}

int main(){
    std::string name  = "JOHN CENA RULES"; // MAX SIZE BEFORE ALLOC

    std::string alloc = "JOHN CENA RULESS"; // goes over and calls new
}