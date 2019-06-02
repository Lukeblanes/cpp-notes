#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

// we can't use void(*func_name)(int) with complex lambdas that pass things through capture
// void ForEach(const std::vector<int>& values, void(*func_name)(int))
void ForEach(const std::vector<int>& values, const std::function<void(int)>& func_name)
{
	for (int value : values)
		func_name(value);
}


int main() 
{
	std::vector<int> values = { 1, 5, 7, 8, 3, 2};

	int a = 5; // let's pass it as a capture

	// lambda definition
	// [] : captures, it's to pass variables so that the lambda function can use them
	// [=]: this means pass everything in by value
	// [&]: pass everything in by reference
	// [a]: pass a by value
	// [&a]: pass a by reference
	// here we defined an inline function with lambda which is a function pointer
	auto lambda = [&a](int value) {std::cout << "Val_lambda: " << value << " a:" << a << std::endl; } ;
	ForEach(values, lambda);

	// if we want to modify what's in the capture we have to specify it's a mutable
	auto lambdi = [&a](int value) mutable { a = 4; std::cout << "Val_lambda: " << value << " a:" << a << std::endl; } ;
	ForEach(values, lambdi);

	// A practical use case of lambda
	// this will look through the vector until it finds an element larger that five and returns an iterator
	auto it = std::find_if(values.begin(), values.end(), [](int value) { return value > 3; } );
	std::cout << *it << std::endl;
}

