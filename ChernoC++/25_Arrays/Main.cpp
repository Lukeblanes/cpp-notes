#include <iostream>

// Storing in the stack
int main()
{
	// type name[size]; with this i allocate enough space for 5 ints
	int example[5];
	int *ptr = example; // legal since example[5] is a pointer

	for (int i = 0; i < 5; i++)
		example[i] = 0;

	example[2] = 5;
	// alternative with pointer
	*(ptr + 4) = 6; // this pointer arithmetic adds depending on the type. since it's an int it adds 4 * sizeof(int) 

	*(ptr) = 6; // example[0]
	
	// accessing. name[index]
	// example[0] = 3;

	// Equivalent to example[2] if example is an int
	*(int*)((char*) ptr + 8) = 26; // doing it by byte since char is only 1 byte. then converting back to int pointer /
	example[4] = 6;

	for(int i = 0; i < 5; i++)
		std::cout << example[i] << std::endl;

	// The way arrays work is by moving by offset, since the memory is contiguous, we just need to know the size of the data and the index to access the element. 
	// Example: int is 4 bytes so if we do example[2], the data we are trying to access is 2 * 4 = 8 bytes forward from where the pointer is referencing. 

	// example[-1];
	// example[5]; // these two give memory access violations. These are dangerous because they might destroy memory that isn't from the array
	//

	// std::cout << example[0] << std::endl;
	std::cout << example << std::endl; // this will print the memory address of the array
}
