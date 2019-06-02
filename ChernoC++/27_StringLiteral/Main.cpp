#include <iostream>
#include <string>
#include <cstring>

#include <stdlib.h> // includes some c libraries
int main()
{
	// "String"; // This is a string literal. In between "
	// At a first glance it's a const char* of size 7 ( the last element is the \0 )
	
	const char name[8] = "Che\0rno";
	// this returns size 3 because it only counts until it finds \0
	std::cout << strlen(name) << std::endl;

	// In this case the size will be correct even though we're not using the whole array
	const char name1[8] = "Cherno";
	std::cout << strlen(name1) << std::endl;


	const char* name2 = "Cherno";
	// the const will prevent us from doing name[1] = 'd';
	// if we remove the const and do name[2] = 'd'; , 
	// depending on the compiler it will do one thing or another
	// since it's undefined behavious. Since it's undefined behavious we 
	// should avoid using it
	//
	// This is because string literals as stored in a read only section of the memory
	// even if we don't put const 
	//
	// If we define it as char name[8] = "Cherno" we can change each char by doing name[1] = 'f';
	
	// There's a wide character type wchar_t
	const wchar_t* name3 = L"Cherno"; // we need to put the L in front since it's a wide char
	
	const char16_t* name4 = u"Cherno"; // this needs the u
	const char32_t* name5 = U"Cherno"; // this needs the U


	// char 	->	1 byte per char
	// wchar	->	2 bytes per char ( but it can depend on the compiler ) 2 on windows / 4 on linux
	// char16 	->	2 byte per char
	// char32	-> 	4 bytes per char
	
	using namespace std::string_literals; // Some additional functionality added
	std::u32string name6 = U"Cherno"s + U" hello";

	// The R will ignore escape chars. Useful for multiline
	const char* example = R"(LIne1
		Line2
		Line3)"; 
	std::cout << example << std::endl;
}

