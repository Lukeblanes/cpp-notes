#include <iostream>
#include <array> // for C++11 array

class Entity
{
public:
	// int example[5]; 
	
	// An easy solution to know the size is with a const variable
	static const int size = 5; // static because it's the same accross all entities
	
	// if we declare the array like this in the stack
	// we create more complexity since we are storing a reference to the block of data
	// This can take a performance hit and memory indirection is not ideal.
	// If we can allocate something on the stack, we should
	int* example = new int[size]; // by using size we don't have to calculate the size



	Entity()
	{
		// a way to figure out the size of an array is like this
		int a[5];

		// The size of a will be 5 * type of array ( int = 4 bytes ) = 20 bytes
		// by doing sizeof(a) 20 / type of the array ( int ) 4 , we get 5
		int count = sizeof(a) / sizeof(int);  
		// this trick only works when it's allocated on the stack but you usually shouldn't depend on this

		// if we do sizeof(example) the size we will get is 4 since it's the size of the pointer

		for (int i = 0; i < 5; i++)
			example[i] = 2;
	}

};

int main()
{
	// The lifetime of this is until we leave the current scope
	int example[5]; // this is how we store in the stack

	for (int i = 0; i < 5; i++)
		example[i] = 2;

	// Arrays in the heap
	
	// The lifetime of this will be until we destroy it or our program ends
	int* another = new int[5];

	for (int i = 0; i < 5; i++)
		another[i] = 2;

	// since we allocated the memory with array, we deallocate it with array
	delete[] another;

	Entity e; // This will create
	// To get to an element we have to access our reference( example ) and then jump to the element we want

	// This kind of array has some overhead since it has bound checking, it mantains a size integer, 
	std::array<int, 5> another; // c++11 array
	// now we can use some modern features
	for (int i = 0; i < another.size(); i++)
		another[i] = 3;
}
