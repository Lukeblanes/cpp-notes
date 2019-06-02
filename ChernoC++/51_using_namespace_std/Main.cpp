#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <string>

// if i do what's below i don't have to write std:: in from of anything
using namespace std;

void ForEach(const vector<int>& values, const function<void(int)>& func_name)
{
	for (int value : values)
		func_name(value);
}

namespace apple {
	// this one takes a std::string
	void print(const std::string& text)
	{
		std::cout << text << std::endl;
	}
}

namespace orange {
	// this one takes a char*
	void print(const char* text)
	{
		std::string temp = text;
		std::reverse(temp.begin(), temp.end());
		std::cout << temp << std::endl;
	}
}

// if we use both namespaces, we get an error. how does the compiler know which one it is
using namespace orange;
using namespace apple;

int main() 
{
	// you can use it inside a scope 
	// using namespace std 
	vector<int> values = { 1, 5, 7, 8, 3, 2};
	auto it = find_if(values.begin(), values.end(), [](int value) { return value > 3; } );
	cout << *it << endl;

	int a = 5; // let's pass it as a capture
	auto lambdi = [&a](int value) mutable { a = 4; cout << "Val_lambda: " << value << " a:" << a << endl; } ;

	ForEach(values, lambdi);


	// namespace ambiguity problem. It calls orange's function because there's no need for a conversion.  
	print("Hello");
	// this is a silent compiler error
	// if we dont use namespace our original code would be
	orange::print("hey");
	apple::print("hey");

}
