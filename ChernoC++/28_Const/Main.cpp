#include <iostream>

class Entity
{
private:
	int m_X, m_Y;
	int *ridiculous;

	// Note: if we put members like this
	int* a, b; 
	// a will be an int* and b will be just an int
	
	// for two pointers
	int *c, *d;

	// If we need variables inside a const function we can use mutable
	mutable int var;
public:
	// when we put const, we are saying that this is not going to modify anything from the class
	int GetX() const 
	{
		var = 6; // LEGAL
		// m_X = 3; // ILLEGAL
		// m_Y = 4; // ILLEGAL ( We can't change anything )
		return m_X;
	}

	// Here we are saying that we are returning a pointer that can't modify what it's pointing to
	// or the contents it's pointing too 
	// and that this function won't modify anything in the class
	const int* const GetTest() const
	{
		return ridiculous;
	}
};

void PrintEntity(const Entity& e)
{
	// we can only call getX if it's const since e is const 
	// if we modified something with getX then it would throw an error
	std::cout << e.GetX() << std::endl;
}

int main()
{
	// by putting const we've syntactically specified that a will not be modified
	// We use it for things data that we need 
	const int MAX_AGE = 90; // Example of usage of const 

	int* a = new int; // Creating it in the heap
	*a = 4;
	std::cout << *a << std::endl;
	a = (int*)&MAX_AGE;
	*a = 43;
	std::cout << *a << std::endl;
	std::cout << MAX_AGE << std::endl;

	const int* b = new int; // Creating it in the heap
	// const with pointer is a different story
	// we can't change the contents of what the pointer is pointing to but we can change the reference
	
	// *b = 4; // ILLEGAL
	b = (int*)&MAX_AGE; // LEGAL
	std::cout << *b << std::endl;


	int* const c = new int;
	// can also be written like int const* a = new int
	// In this case we can change the contents of what the pointer is pointing to
	// but we can't change what the pointer is pointing to
	
	*c = 4; // LEGAL
	// c = (int*)&MAX_AGE; // ILLEGAL
	std::cout << *c << std::endl;

	const int* const d = new int;
	// *d = 4; // ILLEGAL
	// d = (int*)&MAX_AGE; // ILLEGAL
}
