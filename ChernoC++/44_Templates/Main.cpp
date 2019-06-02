#include <iostream>
#include <string>

// Usual case to write a template is a function that does the same for different types

// i might want a function to print integers
/*
void Print(int value)
{
	std::cout << "Val: " << value << std::endl;
}

void Print(std::string value)
{
	std::cout << "Val: " << value << std::endl;
}
*/

// The two functions above do the same thing but are different types. I should use a template here
// The template allows us to write a function but leave the type blanc or variable

// the format is template<typename/class (typename is clearer) typeVariable> function with typevariable

template<typename T>
void Print(T value)
{
	std::cout << "Val: " << value << std::endl;
}
// This isn't actual code. It's created when we call it. and based on the type passed when we create it, 
// it will replace T with the type passed

int main()
{
	// Initial Scenario
	Print(5);

	// What if i want to do the following: 
	Print("Hello");
	// I have to write another function that does a similar thing to the print of the int
	
	// I have to write another function for this
	Print(5.5f);


	// by using templates, i don't have to write a function for every type

	// we can explicitly pass the type when calling a template
	// most of the times the compiler can deduce the type
	Print<float>(6.0f);

	// If we don't use the template, it doesn't exist in the code. It's never created
	
	// The first time we call a template of a specific type, it creates the corresponding function with type
}
