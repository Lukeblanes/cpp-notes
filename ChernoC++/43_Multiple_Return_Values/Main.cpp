#include <iostream>
#include <string>
#include <array>
#include <tuple>

// One solution is to create a struct
struct ShaderProgramSource
{
	std::string VertexSource;
	std::string FragmentSource;
	int a;
};

// Other solution is to have a function which doesn't return anything but modifies the string
static void ParseShader(std::string& outVertexSource, std::string& outFragmentSource)
{
	outVertexSource = "a";
	outFragmentSource = "b";
}

// by using pointer we can pass null
static void ParseShaderPointer(std::string* outVertexSource, std::string* outFragmentSource)
{
	if(outVertexSource)
		*outVertexSource = "a";
	if(outFragmentSource)
		*outFragmentSource= "b";
}

// This would be the old way of array returning. The one below is more modern
static std::string* ParseShaderArray()
{
	std::string a = "C";
	std::string b = "D";
	// this does a heap allocation
	return new std::string[2]{ a, b };
}

// we can change array for vector since array can be variable and doesn't have to have the size
static std::array<std::string, 2> ParseShaderArrayCorrect()
{
	std::string a = "E";
	std::string b = "F";
	// this does a heap allocation
	std::array<std::string, 2> results;
	results[0] = a;
	results[1] = b;
	return results;
}


// This is one of the best ways to use. Clearer and easier to use than tuples or pairs
// it's also very easy to add a new element to it.
struct ShaderProgramSourceGOAT
{
	std::string VertexSource;
	std::string FragmentSource;
};

static ShaderProgramSourceGOAT ParseShaderGoat()
{
	return { "S1", "S2" };
}

int main()
{
	// This way is quite optimal since we aren't copying strings
	std::string vs, fs; // preallocate
	ParseShader(vs, fs); // assign

	ParseShaderPointer(&vs, &fs); // assign
	// with pointer you can specify what you want
	ParseShaderPointer(nullptr, &fs); // don't give me anything for vs
	std::cout << vs << ", " << fs << std::endl;

	// This can be dangerous because we don't know the size of the array
	std::string *sArray = ParseShaderArray();
	std::cout << sArray[0] << ", " << sArray[1] << std::endl;

	// We have to know the type for this to work
	std::array<std::string, 2> results = ParseShaderArrayCorrect();
	std::cout << results[0] << ", " << results[1] << std::endl;

	std::tuple<std::string, std::string> sources = std::make_pair("hello", " world");

	// Code style is not the best for accessing tuple elements
	std::string first= std::get<0>(sources);
	std::string second = std::get<1>(sources);
	std::cout << first << ", " << second << std::endl;

	// difference between tuple and pair is that pair has two, and tuple
	
	ShaderProgramSourceGOAT source = ParseShaderGoat();
	std::cout << source.VertexSource << ", " << source.FragmentSource << std::endl;
}
