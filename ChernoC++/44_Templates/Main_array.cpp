#include <iostream>
#include <string>

// example of templates with class

// we want to create a C style array on the stack
/*
template<int N>
class Array
{
private:
	int m_Array[N]; // The size has to be known at compile time
public:
	int GetSize() const { return N; };
};
*/

// We would end up with this after calling it with
//	Array<5> array;
/*
class Array
{
private:
	int m_Array[5]; // The size has to be known at compile time
public:
	int GetSize() const { return 5; };
};
*/

// Let's suppose we also wanted to specify the type of the array
template<typename T, int N>
class Array
{
private:
	T m_Array[N]; // array of type T and size N
public:
	int GetSize() const { return N; };
};

int main()

{
	// We create the array

	Array<int, 5> array;
	std::cout << array.GetSize() << std::endl;

	Array<std::string, 6> arrayString;
	std::cout << arrayString.GetSize() << std::endl;
}

