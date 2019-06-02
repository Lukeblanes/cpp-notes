#include <iostream>
#include <string>

static int s_Level = 1;
static int s_Speed = 2;

int main()
{
	// Normal way j
	if (s_Level > 5)
		s_Speed = 10;
	else 
		s_Speed = 5;

	// With Ternary operator
	// Variable = Condition ? Value_if_true : Value_if_false;
	s_Speed = (s_Level > 5) ? 10 : 5;

	std::string rank = s_Level > 10 ? "Master" : "Beginner";

	// We can nest conditions inside a ternary operator
	// In this case it's more confusing
	s_Speed = (s_Level > 5) ? s_Level > 10 ? 15 : 10 : 5;


	std::cin.get();

}

