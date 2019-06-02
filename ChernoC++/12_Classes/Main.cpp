#include <iostream>

#define LOG(x) std::cout << x << std::endl;
#define PLAYER(a) std::cout << "x: " << a.x << " y: " << a.y << " speed: " << a.speed << std::endl;

// to move we could create a function move(int x, int y, speed) but there's a better way
// we can create a class

// classes have to have a unique name
class Player
{
public:
	int x, y;
	int speed;

	// since we are in the player class we don't need to pass the player
	// Moving this function inside the class just makes our code cleaner
	void Move(int xa, int ya)
	{
		x += xa * speed;
		y += ya * speed;
	}
};

// we can move this into our class
void Move(Player& player, int xa, int ya)
{
	player.x += xa * player.speed;
	player.y += ya * player.speed;
}

int main() 
{

	// Example of code without classes
	
	// it gets messy really quick
	int PlayerX, PlayerY;
	int PlayerSpeed = 2;

	Player player;
	player.x = 4;
	player.y = 3;
	player.speed = 2;
	Move(player, 1, -1);

	PLAYER(player)

	// with the method ( name for function inside a class ) we call it like this
	player.Move(1, -1);
	PLAYER(player)
}

