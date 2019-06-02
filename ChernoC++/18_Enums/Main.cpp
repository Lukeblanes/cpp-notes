#include <iostream>

// Scenario ...
int A = 0;
int B = 1;
int C = 2;

// we can specify the values of the enum
enum Example : unsigned char // we can specify the type of the enums, they are 32 bit integers by default. It has to be an integer
{
	a = 0, b = 3, c = 7
	// if we do a = 3, b, c , b will be 4, c will be 5
};
// these aren't grouped at all and we might assign a different value by accident
int main()
{
	int value = B; // if we change B, then whatever is below won't work
	if (value == B)
		// do something
	
		std::cout << "test" << std::endl;

	Example val = a; // Here we ensure that val has to be an enum, it can't be 5
}
