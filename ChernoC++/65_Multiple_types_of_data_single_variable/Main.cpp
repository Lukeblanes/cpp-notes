#include <iostream>
#include <string>
#include <fstream>
#include <variant>
#include <optional>

// Class given to us in c++17
// std::variant

// similar to std::optional

// it allows us to worry about the type of data later

int main()
{
	std::variant<std::string, int> data;
	data = "Demo";
	data.index(); // 0
	// to obtain data we do
	std::cout << std::get<std::string>(data) << '\n';
	data = 2;
	data.index(); // 1
	std::cout << std::get<int>(data) << '\n';

	// this can be done but there is no way to retrieve it
	// data = false;
	// std::cout << std::get<bool>(data) << '\n'; ERROR

	// What if we try and access the incorrent type
	// It throws exception but we can handle it in 
	// a different way than with a try/catch

	// we can query the type doing data.index()
	// this will return the index of the type (0: string, 1: int)
	// this depends on how we defined it on the variant definition

	// Instead of just getting the index we can get the value if it's a specific type

	// Returns pointer to data if it's the type we asked for
	auto value = std::get_if<std::string>(&data); 
	std::cout << value << '\n';

	// To obtain depending on type we would do something like this
	if ( auto val = std::get_if<std::string>(&data)  )
	{
		std::string& v = *val;
	} else { // deal
	}

	std::variant<std::string, int> data2;
	// the sizeof of a variant is the sum of the size of its types
	std::cout << sizeof(unsigned long) << '\n';
	std::cout << sizeof(std::string) << '\n';
	std::cout << sizeof(data2) << '\n';
}

// Instead of optional we can use variant
std::optional<std::string> ReadFileAsStringOptional() {
	return {};
}

enum class ErrorCode { None = 0, NotFound, NoPermission};
// In this case we can return the string if everything went okay and
// an error code if the file couldn't be opened
std::variant<std::string, ErrorCode> ReadFileAsStringVariant() {
	return {};
}