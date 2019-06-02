#include <iostream>
#include <tuple>

int main()
{
	auto user_info = std::make_tuple("M", "Chowdhury", 25);

	// to access data
	//std::get<0>(user_info);
	//std::get<1>(user_info);
	//std::get<2>(user_info);

	// C++11, we use tie to do bindings
//	std::string first_name, last_name, age;
//	std::tie(first_name, last_name, age) = user_info;

	// C++17 tuple example.
	auto [first_name, last_name, age] = user_info;

	std::cout << first_name <<std::endl;

}
