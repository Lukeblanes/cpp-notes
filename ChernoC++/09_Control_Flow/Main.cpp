#include <iostream>

int main() 
{
	// Three keyworkds continue, break, return 
	// continue: can be only used inside a loop and it says to go to the next iteration of the loop if there is one
	// break: loop and switch statements, it says get out of the loop
	// return: it will get out of the function you're currently in, most times it requires that it returns a value
	//
	for (int i = 0; i < 5; i++)// variable declaration ; condition ; code called before next execution 
	{
		if ( i % 2 == 0) 
			continue; // in this case it will skip a print
		std::cout << "hello! i = " << i << std::endl;
		continue; // this continue won't make a difference because it's already at the end of the for loop
	}

	for (int i = 0; i < 5; i++)// variable declaration ; condition ; code called before next execution 
	{
		if ( i == 3) 
			break; // it will exit for loop
		std::cout << "hello! i = " << i << std::endl;
	}
	
	for (int i = 0; i < 5; i++)// variable declaration ; condition ; code called before next execution 
	{
		if ( i == 3 ) 
			return 3; // it will exit function and return 3
		std::cout << "hello! i = " << i << std::endl;
	}
}
