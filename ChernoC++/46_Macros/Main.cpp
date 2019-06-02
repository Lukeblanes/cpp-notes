#include <iostream>
#include <string>

// We are saying that whenever it finds the symbol WAIT, replace it with std::cin.get()
// This is a stupid example according to cherno because WAIT could be defined in a different file
#define WAIT std::cin.get()

// Not a good use case 
// #define OPEN_CURLY {

// we can control PR_DEBUG here by changing it 
// 0: Release. no debug
// 1: Standard Debug
// 2: elif example. Debug with pr_debug_2 in console
#define PR_DEBUG 0

// We can also use macros to define things to be done only in debug mode and not in release
// if debug mode, log will print, if not, it won't
#if PR_DEBUG == 1
#define LOG(x) std::cout << x << std::endl
//example of elif
#elif PR_DEBUG == 2
#define LOG(x) std::cout << "PR_DEBUG_2 " << x << std::endl
#else
#define LOG(x)
#endif

// If i don't want to use a macro block at all i can just do

#if 0
// Any macro in here will be disabled unless we change the 0 to 1
#endif

// #ifndef means if defined

// Multiline macro
#define MAIN int main()\
{\
	std::cin.get();\
}
// Not actually used

int main()
// OPEN_CURLY
{
	// Let's say we write std::cin.get() a lot. we can write a macro to simplify writing it
	WAIT;

	// Some actual usefule use case
	// if we write this a lot std::cout << variable << std::endl; we can turn it into a macro
	LOG("HELLO");
	// This will generate std::cout << "HELLO" << std::endl

}
