#include <iostream>
#include <string>
#include <fstream>
#include <optional>

// std optional better way to deal with data that may or may not be there

// V1: return "" if the file couldn't be opened. What if file is valid but empty
// V2: We pass a boolean by reference to indicate if it was correctly opened
// V3: We use std::optional
std::optional<std::string> ReadFileAsString(const std::string& filepath)
{
	std::ifstream stream(filepath);
	if (stream)
	{
		std::string result = "pop";
		// read file
		stream.close();
		return result;
	}

	// V1
	// old way, we just return a something that we know means 
	// it didn't read the file correctly
	// Ex: return std::string; or relturn "";

	// V2: We set the passed boolean by reference to false or true depending on success

	// V3:  
	return {}; // This returns an empty std::optional
}


int main()
{
	// V1: Initial solution
	// std::string data = ReadFileAsString("data.txt");

	//	if (data != "")  

	// V2: Better but still not clean
	// std::string data = ReadFileAsString("data.txt");
	//	bool openFileSuccess;
	//	std::string data = ReadFileAsString("data.txt", openFileSuccess);
	//	if (openFileSuccess)  

	// V3
	std::optional<std::string> data = ReadFileAsString("data.txt");

	// if the data is none, we asign a value to use
	std::string value = data.value_or("Not present");
	if (data)  // if true, it was opened correctly
	{
		// to access data we do 
		std::cout << "File read succesfully " << data.value() << '\n';
	} 
	else 
	{
		std::cout << "File could not be opened" << value <<"\n" ;
	}
	return 0;
}

