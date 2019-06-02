#include <iostream>

// basic primitive types and sizes ( there are other primitive types
// char -> 1 byte
// short -> 2 bytes
// int -> 4 bytes
// long -> 4 bytes (depends on compiler )
// long long -> 8 bytes

//
// float
// double

// bool
// there's a variation between unsigned and unsigned

// these are the building blocks for more complex data
// all variables can be references or pointers

int main()
{
	float t = 5.5f; // by putting f we specify it's float and not a double
	double t2 = 5.5; // double
	// How can we know size of things
	std::cout << "char: " << sizeof(char) << std::endl;
	std::cout << "short: " << sizeof(short) << std::endl;
	std::cout << "int: " << sizeof(int) << std::endl;
	std::cout << "long: " << sizeof(long) << std::endl;
	std::cout << "long long: " << sizeof(long long) << std::endl;
	std::cout << "float: " << sizeof(float) << std::endl;
	std::cout << "double: " << sizeof(double) << std::endl;
	std::cout << "bool: " << sizeof(bool) << std::endl;
}
