#include <iostream>
#include <string>
#include <tuple>

// We could use a pair instead of a tuple but 
// a tuple allows us to expand if we want to add
// more attributes.
std::tuple<std::string, int> CreatePerson()
{
	return { "Luke", 23 };

}

int main()
{
	auto person = CreatePerson();

// to get the data from the tuple we would have to do the following
	std::string& nameG = std::get<0>(person);
	int ageG = std::get<1>(person);
	std::cout << nameG << " " << ageG << '\n';

// There is another option to do this with tie which is slightly cleaner 
// Using a struct is still nicer than using this method
	std::string nameT;
	int ageT;
	std::tie(nameT, ageT) = CreatePerson();
	std::cout << nameT << " " << ageT << '\n';

// in c++17, structured binding is introduced which allows us to do the following
	auto[nameB, ageB] = CreatePerson();
	nameB = "fjdkslj";
	std::cout << nameB << " " << ageB << '\n';

}

