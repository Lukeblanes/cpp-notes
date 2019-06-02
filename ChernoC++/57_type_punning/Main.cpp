#include <iostream>

struct Entity
{
	int x, y;
};

int main()
{
	int a = 50;
	double value = a; // this has converted an int to a double
	value = (double)a; // explicit conversion as opposed to implicit which is done above

	// dangerous because int and double have different byte sizes
	value = *(double*)&a;
	// we are converting the reference to a to a double pointer and then dereferencing and then storing it to value
	// After converting it to a double pointer when we dereference we are dereferencing 8 bytes instead of 4.
	// We are reading from memory that is not ours

	std::cout << value << std::endl;

	// Practical Example
	Entity e = { 5, 8 }; // if we look at the memory of this, it's just 8 bytes (4bytes * 2 ints)

	// I've basically converted it to an array is the "disposition" of the memory is the same in a struct and an array
	int *position = (int*)&e; // pointer to the struct
	 
	std::cout << position[0] << ", " << position[1] << std::endl;

	// get y. sane person int y = e.y;
	// insane person, using raw memory operations for accessing struct members. 
	// No one would actually use this 
	int y = *((int*)&e + 1); // int pointer version is +1
	int y_char = *((char*)&e + 4); // char pointer version is +4
	int y_char_cherno = *(int*)((char*)&e + 4); // cherno casts it back to (int*) before dereferencing
	std::cout << y << ", " << y_char << ", " << y_char_cherno << std::endl;
	
	 

}
