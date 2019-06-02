#include <iostream>
#include <array>

// Let's say we have a function to print an array
void PrintArray(int *array, unsigned int size) // we have to pass the size because we can't get it from the pointer
{

}

// passing the std::array we still have to indicate the size in the parameter
// to avoid having to determine size here we can use a template
template<size_t SIZE>
void PrintArraySTD(const std::array<int, SIZE>& array)
{
	for( int i = 0; i < array.size(); ++i)
	{
		std::cout << array[i] << std::endl;
	}
}
int main()
{
	// takes 2 template arguments, optionally it can take 1 ( just the type ). 
	// First arg: type, Second arg: number of elements
	// It is highly recommended to always pass the 2 template arguments
	std::array<int, 5> data;
	data[0] = 2;
	data[1] = 8;
	data[2] = 9;
	data[3] = 4;
	data[4] = 1;

	// c-style array
	// the biggest drawback from this type of array is that we always have to keep track of the size
	int dataOld[5];
	dataOld[0] = 2;
	dataOld[5] = 43; // this will overwrite data we don't own

	// Why would we use std::array
	PrintArraySTD<data.size()>(data);  

	// other advantages of array is
	data.begin(); // iterator
	// we can sort with std::sort 
	// There is bound checking, if we do data[5], an error will appear
}
