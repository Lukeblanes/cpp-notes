#include <iostream>
#include <string>

int main()
{

	// first encounter of a type of string in c++
	// This is a C-style way of declaring strings
	const char* name = "Odysseus"; 

	std::cout << name << std::endl;

	// we can declare it without const but we don't really want to go around changing char*
	// Strings start to where char* is pointing to and we know the end thanks to the \0 symbol which indicates that it's the end of the string

	char name2[7] = { 'C', 'h', 'e', 'r', 'n', 'o', '\0'};
	std::cout << name2 << std::endl;

	// In c++ we should be using std::string
	
	std::string nameS = "Odysseo";
	// we can't do nameS = "hello " + "world"; but we can concatenate like this:
	nameS += "'s chile";
	std::cout << nameS << std::endl;
	// too append two strings during initialization we can do
	nameS = std::string("HOY") + " Ayer";
	std::cout << nameS << std::endl;

	
	// string provides various functions so we can do nameS.size() something that char* couldn't do
	//
	// to find text we can use 
	// bool name.find("no") != std::string::npos; // true or false if it finds
}

// if we wanted to write a function that uses string we wouldn't write it like
// because std::string string is a copy
void PrintString(std::string string)
{
	std::cout << string << std::endl;
}

// Since it's read only we use const and by passing the reference we only create a copy of the reference and not the whole std::string
void PrintStringGood(const std::string& string)
{
	std::cout << string << std::endl;
}
