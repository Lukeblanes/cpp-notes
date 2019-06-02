#include <iostream>
#include <chrono>
#include <thread>

// Struct for timing
// we are going to use the object lifetime concept for timing 
struct Timer
{
	std::chrono::system_clock::time_point start, end;
	std::chrono::duration<float> duration;
	Timer()
	{
		start = std::chrono::high_resolution_clock::now();
	}

	~Timer()
	{
		end = std::chrono::high_resolution_clock::now();
		duration = end - start;

		float ms = duration.count() * 1000.0f; // converting to ms
		std::cout << "Timer took " << ms << "ms" << std::endl;
	}
	
};

void Function()
{
	// Now To time this function i just have to do the following
	Timer t;
	for (int i = 0; i < 100; i++)
		std::cout << "hello\n";
}
int main()
{
	// for 1s for thread sleep time
	using namespace std::literals::chrono_literals;

	// returns a time which is an object from chrono library
	auto start = std::chrono::high_resolution_clock::now();

	std::this_thread::sleep_for(1s);
	auto end = std::chrono::high_resolution_clock::now();

	// we explicitly write the type so that it returns float
	std::chrono::duration<float> duration = end - start;


	std::cout << duration.count() << "s " << std::endl;


	// There's a smarter way of writing timing code. Using a struct
	Function();
}
