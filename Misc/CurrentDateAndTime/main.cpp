#include <iostream>

#include <chrono>  // chrono::system_clock
#include <ctime>   // localtime
#include <sstream> // stringstream
#include <iomanip> // put_time
#include <string>  // string

std::string GetCurrentTimeAndDate()
{
	auto now = std::chrono::high_resolution_clock::now();
	auto in_time_t = std::chrono::high_resolution_clock::to_time_t(now);

	std::stringstream ss;
	ss << std::put_time(std::localtime(&in_time_t), "%Y-%m-%d %X");
	return ss.str();
}

int main()
{
	std::cout << "Current time and date is: ";
	std::cout << GetCurrentTimeAndDate() << "\n";
}