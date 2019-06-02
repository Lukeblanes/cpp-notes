#include <iostream>

//
int Multiply(int a, int b)
{
	return a*b;
}

// void means return nothing

void MultiplyAndLog(int a, int b)
{
	int result = Multiply(a, b);
	std::cout << result << std::endl;
}

// the usage of functions is normally to avoid code duplication

int main() // the main function doesn't have to return there's an implicit return 0; at the end
{
	// we originally have these three calls
	int result = Multiply(3, 2);
	std::cout << result << std::endl;

	int result1 = Multiply(9, 2);
	std::cout << result1 << std::endl;

	int result2 = Multiply(3, 5);
	std::cout << result2 << std::endl;


	// Once we abstract because of duplicate code
	MultiplyAndLog(3, 2);
	MultiplyAndLog(9, 2);
	MultiplyAndLog(3, 5);
}
