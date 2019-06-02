#include <iostream>


// This will be our base class. All entities will have a position
class Entity
{
public:
	float X, Y;

	void Move(float xa, float ya)
	{
		X += xa;
		Y += ya;
	}
};

// What we would do without inheritance. A lot of duplicated code
/*
class Player 
{
public:
	char * Name; // It's the same as Entity but has a name
	float X, Y;

	void Move(float xa, ya)
	{
		X += xa;
		Y += ya;
	}

	void PrintName() // It also adds this functino
	{
		std::cout << Name << std::endl;
	}
};
*/

// Player Inherits from Entity which means that player is both an Player and an entity
class Player : public Entity 
{
public:
	char * Name; 

	void PrintName() 
	{
		std::cout << Name << std::endl;
	}
};

int main()
{
	Player player;
	
	// i can access entity attributes and methods with player since it extends from entity
	player.Move(2, 5);
	player.X = 35;
	player.PrintName();
	std::cout << sizeof(Entity) << std::endl;
	std::cout << sizeof(Player) << std::endl;
	std::cin.get();
}
