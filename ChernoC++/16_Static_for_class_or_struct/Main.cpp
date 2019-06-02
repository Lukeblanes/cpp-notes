#include <iostream>

#define LOG(x) std::cout << x << std::endl;
#define PLAYER(a) std::cout << "player -> x: " << a.x << " y: " << a.y << " speed: " << a.speed << std::endl;
#define VEC2(a) std::cout << "vec2 -> x: " << a.x << " y: " << a.y << std::endl;

// we are using a struct because the attributes will be public by default
struct Entity
{
	static int x, y;

	// this function can be static since it uses static variables.
	// static methods don't have an instance and can't access non-static attributes
	static void Print()
	{
		std::cout << "x: " << x << " y: " << y << std::endl;
	}
};

// Since x and y are static they are only available inside the strruct so we have to declare them

int Entity::x;
int Entity::y;
int main() 
{
	Entity e;
	e.x = 2;
	e.y = 3;

	// Another way to declare struct or class?
	// This will not work if x and y are static but the above way will
	// Entity e1 = { 1, 4 };
	Entity e1;
	e1.x = 1;
	e1.y = 4;

	// When we change x and y for e1 we are changing them for all instances of Entity
	
	// Since x and y are shared for all entity instances we can access them like this
	
	Entity::x = 6;
	Entity::y = 21;
	

	e.Print();
	e1.Print();

	// since Print is static we can call it like this
	Entity::Print();


	// In this case in particula we wouldn't even need struct instances it would be equivalent to doing
	Entity::x = 1;
	Entity::y = 4;

	Entity::x = 6;
	Entity::y = 21;

	Entity::Print();
	Entity::Print();
	std::cin.get();
}

