#include <iostream>
#include <string>
#include <variant>
#include <any>

// c++17 way of storing data
// std::any

int main()
{
	std::any data;
	data = 2;
	data = "luke";
	data = std::string("luke");

	// to retrieve we need to know the type
	std::string name = std::any_cast<std::string>(data); // Will throw exception if they aren't the same type

	// any is a typesafe union
	// it stores its data in a union if it's a simple type

	// if the type we are trying to store is more complex, it will probably allocate it dynamically

	// if we want to return the reference instead of copying use &
	std::string &name = std::any_cast<std::string&>(data); // Will throw exception if they aren't the same type

	// "If you need a variable that needs to be able to store anything, redesign your program"
}
