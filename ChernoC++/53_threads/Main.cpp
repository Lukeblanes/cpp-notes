#include <iostream>
#include <thread>

static bool s_Finished = false;

// function for thread
void DoWork()
{
	using namespace std::literals::chrono_literals; // for 1s
	// Sometimes threads can use up all the cpu of a thread so we can use sleep to slow it down

	// print current thread
	std::cout << "Thread id = " << std::this_thread::get_id() << std::endl;

	while(!s_Finished)
	{
		std::cout << "Working..." << std::endl;
		// stop thread for a second
		std::this_thread::sleep_for(1s);
		// this_thread is to access the current thread that is executing this function
	}
}

// We want to run working until the use presses enter
int main()
{
	// a thread takes a function pointer that will be executed by the thread
	std::thread worker(DoWork);


	// after the user presse enter, s_Finished will be set to false and the thread will finish
	std::cin.get();
	s_Finished = true;
	
	// Blocks the current thread until the thread worker has finished it's execution
	worker.join(); 
	std::cout << "Finished" << std::endl;
	
	// to print current thread we do
	std::cout << "Thread id = " << std::this_thread::get_id() << std::endl;

	std::cin.get();

}

