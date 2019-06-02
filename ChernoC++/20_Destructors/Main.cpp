#include <iostream>

class Entity
{
public:
	float X, Y;

	Entity()
	{
		std::cout << "Created Entity!" << std::endl;
		X = 0.0f;
		Y = 0.0f;
	}

	// Destructor: It gets called when we leave the scope the Entity was created in
	~Entity()
	{
		std::cout << "Destroyed Entity!" << std::endl;
	}

	void Print()
	{
		std::cout << X << ", " << Y << std::endl;
	}
};

int main()
{
	Entity e;
	e.Print(); 
	e.~Entity(); // We can manually call the destructor but then the destructor will be called twice
	// We don't normally call the destructor manually
	std::cin.get();
}
