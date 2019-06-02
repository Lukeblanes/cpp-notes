#include <iostream>

class Entity
{
public:
	float X, Y;

	// Solution 1
	// with this method every time we create an entity we have to write the init function
/*	void Init() { 
		X = 0.0f;
		Y = 0.0f;
	}
	*/

	// Solution 2
	// Constructor. Gets called every time an entity is created
	Entity()
	{
		X = 0.0f;
		Y = 0.0f;
	}

	// if we don't specify a constructor there's still a default constructor but it doesn't do anything
	// the default constructor would be equivalent to:
//	Entity() { } 

	// Other constructor
	Entity(float x, float y)
	{
		X = x;
		Y = y;
	}
	void Print()
	{
		std::cout << X << ", " << Y << std::endl;
	}
};

// if we want to avoid people instatiating a class and only using static function we can do this:

class Log
{
// OPTION 1: constructor in private
private:
	// Log() {} // by putting Log as private it can't be instantiated

public:
	// OPTION 2: In public with delete
	Log() = delete;

	static void Write()
	{

	}
};

// if i create an Entity and call print, we will get random values because X and Y weren't initialised
// with a constructor we set a default value when we create an entity so that we don't get random values of x and y
int main()
{
	Entity e;
	// e.Init(); // We don't need this if we have constructor
	std::cout << e.X << ", " << e.Y << std::endl; // won't give error if they're initialised
	e.Print(); 
	Entity e1(2.3f, 3.2f);
	e1.Print(); 
	std::cin.get();

	// Log l; isn't allowed because we've overwriten the default constructor which is by default public to be private
}
