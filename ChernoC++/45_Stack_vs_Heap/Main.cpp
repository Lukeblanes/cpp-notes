#include <iostream>
#include <string>

struct Vector3
{
	float x, y, z;

	// default constructor
	Vector3():
		x(10), y(20), z(30) 
	{
	}
};

int main()
{
	// The main difference is the new keyboard. new allocates on the heap
	int value = 5; // This is how to allocate an integer on the stack
	int array[5]; // allocate int array on stack
	array[0] = 1; 
	array[1] = 2; 
	array[2] = 3; 
	array[3] = 4; 
	array[4] = 5; 
	Vector3 vector; // allocate struct/class on the stack
	// If we look at where the variables are allocated in the stack, they are all quite close together
	// The memory is stored on top of each other, like a stack
	// That's why stack allocation is really fast
	// In the stack, once it leaves the scope, it's automatically destroyed

	int *hvalue = new int; // allocate int on the heap
	*hvalue = 5;
	int *harray = new int[5];// allocate int array on heap 
	harray[0] = 1; 
	harray[1] = 2; 
	harray[2] = 3; 
	harray[3] = 4; 
	harray[4] = 5; 
	Vector3* hvector = new Vector3(); // allocate struct/class on the heap ( parentheses optional )

	// If we are using smart pointers, they still allocate on the heap
	// an important thing is to delete memory created with new
	
	delete hvalue;
	delete[] harray;
	delete hvector;

}

