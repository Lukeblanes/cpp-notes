#include <iostream>

int main() // the main function doesn't have to return there's an implicit return 0; at the end
{
	int x = 5;
	bool comparisonResult = x == 5;
	// == is an overloaded operator that will return 0 or anything else(usually 1) depending on x and 5
	
	if ( comparisonResult ) // we don't have to do comparisonResult == 5
		std::cout << "hello world!" << std::endl;

	// since anything that's 0 is evaluated as false we can use tricks to see if a pointer is null
	
	const char* ptr = "Hello";
	if (ptr)
		std::cout << "ptr: " << ptr << std::endl;

	const char* ptr_test = "test"; // this will evaluate as false since it's a null pointer ( 0 ) 
	if ( ptr_test == "test" )
		std::cout << "test string is on " << std::endl;
	else if ( ptr_test ) 
		std::cout << "ptr_test: " << ptr_test << std::endl;
	else
		std::cout << "ptr_test is null" << std::endl;
}
