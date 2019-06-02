#include <iostream>

int main()
{
	// int *array = new int[50]; // allocating 200 bytes for 50 ints

	// for multidimensional array i want a pointer of pointers
	// It's a pointer to a collection of pointers
	// The allocation of multidimensional arrays is a bit complicated
	int** a2d = new int*[50]; // allocated 200 bytes of memory. ( memory to store the pointers) 

	// Even though in both cases we have allocated the same amount of memory they are different types
	// array[0] = 3; // here we are dealing with ints
	a2d[0] = nullptr; // here we are dealing with pointers

	// After allocating those 200 bytes for pointers, we can allocate our 50 arrays and store the pointers to those arrays in a2d
	
	// allocating space for arrays of size 50, and storing the pointer to the allocated memory to a2d[i]
	for (int i = 0; i < 5; i++)
		a2d[i] = new int[5];
	
	// With this for loop we assign each element
	for (int i = 0; i < 5; i++)
	{
	  	for (int j = 0; j < 5; j++)
	  	{
	  		a2d[i][j] = 2; // The cool thing about this is that it's like a 2d grid
	  	}
	}

	// To delete we have to do it in the inverse order first deallocate the arrays and then the array of pointers
	
	for (int i = 0; i < 5; i++)
		delete[] a2d[i];
	delete[] a2d; // if we delete this first we can't access to the individual arrays 



	// Here is how we would allocate a 3d array
	/*
	 * int*** a3d = new int**[50];
	 * for (int i = 0; i < 50; i++)
	 * {
	 * 	a3d[i] = new int*[50];
	 * 	for (int j = 0; j < 50; j++)
	 * 	{
	 * 		a3d[i][j] = new int[50];
	 * 	}
	 * }
	 * // We would access it like this
	 * a3d[0][0][0] = 0; // Access element
	 * a3d[0] // array of pointer to pointer
	 * a3d[0][0] // array of pointers
	 *
	 */

	// way of avoiding using multidimensional arrays
	int* array = new int[5 * 5];
	for(int i = 0; i < 5*5; i++)
	{
		array[i] = 2;
	}

	// if we need the grid aspect of the multidimensional array we can do this
	// this for loop is much faster than the multidimensional array code
	for (int i = 0; i < 5; i++)
	{
	  	for (int j = 0; j < 5; j++)
	  	{
	  		array[j + i * 5] = 2; 
	  	}
	}
	delete[] array;
}
