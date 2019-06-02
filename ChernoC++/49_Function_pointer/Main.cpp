#include <iostream>
#include <vector>

// test function
void HelloWorld()
{
	std::cout << "hello world" << std::endl;
}

void HelloWorld_Param(int a)
{
	std::cout << "hello world Val: " << a << std::endl;
}


// usefule use case

// function examples: it's weird to have functions that will only be used to pass by pointer
// so we can use lambda functions instead
void PrintValue(int value)
{
	std::cout << "Value: " << value << std::endl;
}
void PrintValueAlt(int value)
{
	std::cout << "Value_ALt: " << value << std::endl;
}

void ForEach(const std::vector<int>& values, void(*func_name)(int))
{
	// what if i wanted a way to pass what we do with the values, we can use pointer functions
	for (int value : values)
		func_name(value);

}


int main() 
{
	// auto function = HelloWorld(); // here HelloWorld returns void
	// auto function = &HelloWorld; // if we don't put the ampersand it's converted to a pointer anyway
	auto function = HelloWorld; // if we remove parenthesis (not calling function) we get the function pointer

	// void(*var_name)(parameter_types [ex:(std::string, int)] )
	void(*function_explicit_declaration)() = HelloWorld;
	// i can now call with the function pointer like this
	function();
	function();
	function_explicit_declaration();

	// since the full declaration is a bit awkward people use auto or typedef
	// typedef example
	typedef void(*HLFunc)();
	HLFunc f= HelloWorld;
	f();

	typedef void(*HLFunc_para)(int);

	HLFunc_para t = HelloWorld_Param;
	t(4);

	// useful use case

	std::vector<int> values = { 1, 5, 7, 8, 3, 2};
	// we have a function that passes each element of the vector to a function
	ForEach(values, PrintValue); 
	ForEach(values, PrintValueAlt); 

	// example using lambda function
	ForEach(values, [](int value) {std::cout << "Val_lambda: " << value << std::endl; } );
}
