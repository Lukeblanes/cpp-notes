#include <iostream>
#include <memory>
#include <array>

#include <chrono>

// One way of doing a portable Break point
#define BREAKPOINT \
    asm("int $3")


class Timer
{
public:
	Timer()
	{
		m_StartTimepoint = std::chrono::high_resolution_clock::now();
	}

	~Timer()
	{
		// To make the timer scope based (RAII pattern)
		Stop();
	}

	void Stop()
	{
		auto endTimepoint = std::chrono::high_resolution_clock::now(); 

		auto start = std::chrono::time_point_cast<std::chrono::microseconds>(m_StartTimepoint).time_since_epoch().count();
		auto end = std::chrono::time_point_cast<std::chrono::microseconds>(endTimepoint).time_since_epoch().count();

		auto duration = end - start;

		double ms = duration * 0.001;

		std::cout << duration << " us (" << ms << " ms)\n";
	}

private:
	std::chrono::time_point<std::chrono::high_resolution_clock> m_StartTimepoint;

};


int main()
{
	int value = 0;

	// since the timer is scope based,
	// we just wrap it in a scope
	{
		Timer timer;

		for (int i = 0; i < 1000000; i++)
			value += 2;
	}

	std::cout << value << "\n";

	// BREAKPOINT;
	// __debugbreak(); (Windows version)	

	struct Vector2
	{
		float x, y;
	};

	std::cout << "Make Shared\n";
	{
		std::array<std::shared_ptr<Vector2>, 1000> sharedPtrs;
		Timer timer;
		for (int i = 0; i < sharedPtrs.size(); i++)
			sharedPtrs[i] = std::make_shared<Vector2>();
	}

	std::cout << "New Make Shared\n";
	{
		std::array<std::shared_ptr<Vector2>, 1000> sharedPtrs;
		Timer timer;
		for (int i = 0; i < sharedPtrs.size(); i++)
			sharedPtrs[i] = std::shared_ptr<Vector2>(new Vector2());
	}
	BREAKPOINT;

	std::cout << "Unique\n";
	{
		std::array<std::unique_ptr<Vector2>, 1000> sharedPtrs;
		Timer timer;
		for (int i = 0; i < sharedPtrs.size(); i++)
			sharedPtrs[i] = std::unique_ptr<Vector2>(new Vector2());
	}
}


