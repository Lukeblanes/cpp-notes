#include <iostream>

int main() // the main function doesn't have to return there's an implicit return 0; at the end
{
	for (int i = 0; i < 5; i++)// variable declaration ; condition ; code called before next execution 
		std::cout << "hello " << std::endl;

	// equivalence in for loop
	// i  =  0
	// i < 5
	// print
	// i++
	//
	// i < 5
	// print 
	// i++
	// .
	// .
	// .
	
	int i = 0; // Another way two write it
	bool condition = true;
	for ( ; condition ; ) // for ( ; ; ) == for ( ; true ; )
	{
		std::cout << "hello world " << std::endl;
		i++;
		if ( ! ( i < 5 ) )
			condition = false;
	}

	// While loops and for comes down to if you need a variable
	i = 0;
	while ( i < 5 )
	{

	}

	// for array for example, for loop

	do // the do will execute at least once and then evaluate the condition
	{
	} while ( i < 5 ) 
}
