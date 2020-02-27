#include <iostream>
#include <string>

// the main reason std::string is slow or any string is that they allocate memory on the heap.

static uint32_t s_AllocCount = 0;

// An easy way to see how many allocations are done is to override the new operator
void* operator new(size_t size)
{
	s_AllocCount++;
	std::cout << "Allocating " << size << " bytes\n";
	return malloc(size);
}

void PrintName(const std::string& name)
{
	std::cout << name << std::endl;
}

// string_view version
void PrintName(std::string_view name)
{
	std::cout << name << std::endl;
}

int main()
{
	// It allocates on the heap when char is more than 16 bytes ( 16 or more chars )

	// Version 1
	/*
	std::string name = "Jimmiess Bonhams";
	PrintName(name);
	*/

	// This also allocates memory
	/*
	PrintName("Jimmiess Bonhams");
	*/

	// Contrived Example

	// This only does one allocation since substrings are smaller than 17 bytes
#if 0
	std::string name = "Jimmiess Bonhams is the best rockstar in the whole world";

	std::string guitarist = name.substr(0, 17); // big enough for allocation
	std::string drummer = name.substr(3, 20);
	PrintName(name);
	PrintName(guitarist);
	PrintName(drummer);
	PrintName(name.substr(9, 17)); // Allocation if higher than 16
	
#elif 0
	// Instead of copying a string when doing the substring operation we can use a view.
	// The view is a pointer to whichever part of the string we're interested in.
	std::string name = "Jimmiess Bonhams is the best rockstar in the whole world";

	// string_view version with only 1 allocation
	std::string_view guitarist_view(name.c_str(), 17);
	std::string_view drummer_view(name.c_str() + 3, 17);
	PrintName(guitarist_view);
	PrintName(drummer_view);
#else
	// Version with 0 allocations
	const char* name = "Jimmiess Bonhams is the best rockstar in the whole world";
	std::string_view guitarist_view(name, 17);
	std::string_view drummer_view(name+ 3, 17);
	PrintName(guitarist_view);
	PrintName(drummer_view);
#endif

	std::cout << s_AllocCount << " allocations.\n";
	return 0;	
}