#include <iostream>
#include <string>

class Entity 
{
private: // Only this class ( or friends of this class ) can use X and Y or any other private function or member
	int privateX, privateY; // default visibility is private

	void Print() {}

protected:
	int protectedX, protectedY;
public:
	int publicX, publicY;
	Entity()
	{
		privateX = 0; // OK
		Print(); // OK
		protectedX = 0; // OK
		publicX = 0; // OK
	}
};

class Player : public Entity 
{

public:
	Player()
	{
		// privateX = 2; can't do this since X is private
		// Print(); NOPE
		protectedX = 0; // OK
		publicX = 0; // OK
	}
};

int main()
{
	Entity e;
	// e.privateX = 2; can't do this since X is private
	// e.Print() NOPE
	
	// e.protectedX  = 0; NOPE
	e.publicX = 0; // OK
	std::cin.get();
}
