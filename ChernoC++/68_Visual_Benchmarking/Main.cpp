#include <iostream>
#include <string>

#include <cmath>
#include <memory>
#include <array>

#include <chrono>

// In linux we need to include pthread to use threads
// Instruction: g++ -std=c++17 -pthread Main.cpp 

// #include "timer.h"
#include "instrumentor.h"

// We don't always want to profile our code
// We can solve this by using macros
// We can also use function names 

#define PROFILING 1
#if PROFILING 
#define PROFILE_SCOPE(name) InstrumentationTimer timer##__LINE__(name)
// Function name: __FUNCTION__
// Function signature windows: __FUNCSIG__
// Function signature linux: __PRETTY_FUNCTION__
#define PROFILE_FUNCTION() PROFILE_SCOPE(__PRETTY_FUNCTION__)
#else
// #define PROFILE_SCOPE(name)
#define PROFILE_FUNCTION()
#endif

// With the macros we can just write PROFILE_FUNCTION for any new function we create

// What if we have overloaded functions
void PrintFunction(int value)
{
	PROFILE_FUNCTION();
	for(int i = 0; i < 1000; i++)
	 {
		 std::cout << "Hello #" << (i + value) << "\n";
	 }
}

void PrintFunction()
{
	PROFILE_FUNCTION();
	for(int i = 0; i < 1000; i++)
	 {
		 std::cout << "Hello #" << i << "\n";
	 }
}

void foo()
{
//	PROFILE_SCOPE("foo");
	PROFILE_FUNCTION();
	for(int i = 0; i < 1000; i++)
	 {
		 std::cout << "Hello #" << i << "\n";
	 }
}

void bar()
{
//	PROFILE_SCOPE("bar");
	PROFILE_FUNCTION();
	for(int i = 0; i < 1000; i++)
	 {
		 std::cout << "Hello #" << sqrt(i) << "\n";
	 }
}

void RunBenchmarks()
{
	// PROFILE_SCOPE("RunningBenchmarks");
	PROFILE_FUNCTION();
	std::cout << "Running Benchmarks ...\n";
	foo();
	bar();
	
	// added functions using threads
	std::thread a([]() { PrintFunction(3); } );
	std::thread b([]() { PrintFunction(); } );

	a.join();
	b.join();
	// Using joing so that it doesn't exit the function until they end. 
}

int main()
{
	Instrumentor::Get().BeginSession("Profile");
	RunBenchmarks();
	Instrumentor::Get().EndSession();

	// to view profiling data, we go to chrome's chrome://tracing
}

// NOTES: we can use this for any function
// if we just want to profile a specific part of the code we can 
// create a scope so that when so that it times when it exits the scope.