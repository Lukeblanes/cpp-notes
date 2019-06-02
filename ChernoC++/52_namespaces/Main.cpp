#include <iostream>
#include <string>
#include <algorithm>

// we have the issue of having two functions with the same name
// if we wrape them with namespace we can have them

namespace apple {

	void print(const char* text)
	{
		std::cout << text << std::endl;
	}
}

namespace orange {

	void print(const char* text)
	{
		std::string temp = text;
		std::reverse(temp.begin(), temp.end());
		std::cout << temp << std::endl;
	}
}

namespace pear { namespace banana {

	void print(const char* text)
	{
		std::cout << "PB_" << text << std::endl;
	}
} }

int main() 
{
	// with namespaces we're allowed to have 2 functions with the same signature in the same context
	apple::print("hey");
	orange::print("hey");

	// we can use the using for namespaces
	using namespace apple;
	print("fhdksalñ");

	// and we can also do it for specific functions
	using orange::print; // this overrided the using namespace apple
	print("TEST");

	// we can also use aliases ( useful for nested namespaces
	namespace a = pear::banana;
	a::print("alias");

	// all of these namespace declarations are limited to the scope
	// when we leave the scope the namespace declarations are destroyed
}
