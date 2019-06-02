#include <iostream>
#include <vector>
#include <algorithm> // includes sort
#include <functional> // includes sorting predicates ( function )

int main()
{
	std::vector<int> values = { 3, 5, 1, 4, 2};
	// this function has 3 parameters
	// 1st: start
	// 2nd: end
	// 3rd: ordering predicate
	// If i don't specify a predicate it will just order in ascending order
	std::sort(values.begin(), values.end()); 

	// this will sort based on greater value
	std::sort(values.begin(), values.end(), std::greater<int>()); 

	// sorting with lambda. this sorts in ascending order except for 1
	std::sort(values.begin(), values.end(), [](int a, int b) 
		{ 
			if ( a == 1)
				return false;
			else
				return (a < b); 
		}); 

	for (int value : values)
		std::cout << value << std::endl;
}
