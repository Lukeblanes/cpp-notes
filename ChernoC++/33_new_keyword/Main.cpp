#include <iostream>
#include <string>

// this is so we don't have to write std::string where all the strings are
using String = std::string;

class Entity
{
private:
	String m_Name;
public:
	Entity() : m_Name("Unknown") {}
	Entity(const String& name) : m_Name(name) {}

	const String& GetName() const { return m_Name; }
};



int main()
{
	int a = 2; // stack
	// int *b = new int; // heap: single 4 byte integer, b stores the memory address

	int *c = new int[50]; // example of array, 200 bytes ( 50 * 4 bytes )
	//
	Entity *e = new Entity();
	// Entity *e = new Entity[45] // array example
	
	// In the case of a class it doesn't just allocate the neccessary memory, it also calls the constructor
	// Usually new calls malloc -> which allocates memory and returns a pointer
	// Entity *e = new Entity(); is sort of equivalent to doing Entity *e = (Entity*)malloc(sizeof(Entity));
	// The only difference is that new calls the constructor and malloc doesn't 
	// there are only very specific cases where we should use malloc in c++, but we usually shouldn't use it. 
	
	
	// Something we have to do after allocating memory is to free it.
	// the c equivalent to delete is free. Delete additionally calls the destructor of the class.
	delete e;
	delete[] c; // if we allocate with brackets, deallocate with brackets
}
