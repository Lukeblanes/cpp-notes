#include <iostream>
#include <string>
#include <memory> // to access smart pointers

class Entity
{
public: 
	Entity() 
	{
		std::cout << "Created Entity! " << std::endl;
	}

	~Entity()
	{
		std::cout << "Destroyed Entity! " << std::endl;
	}

	void Print() {}
};

int main() 
{

	// unique_ptr example
	{
		// std::unique_ptr<Entity> entity = new Entity(); // You can't use implicit conversion with smart pointers
		// Not recommended but valid
//		std::unique_ptr<Entity> entity(new Entity());

		// Prefered way due to exception safety
		std::unique_ptr<Entity> entity = std::make_unique<Entity>();

		// This can't be done, unique pointers can't be copied
//		std::unique_ptr<Entity> e1 = entity;

		entity->Print();
		// Entity gets destroyed when it leaves the scope
	}

	// shared_ptr example
{
	std::shared_ptr<Entity> s1;
	{
		std::shared_ptr<Entity> sharedEntity = std::make_shared<Entity>();

		// With shared pointer you can't do this since the shared_ptr needs more overhead for the reference counting aspect of the pointer
		// std::shared_ptr<Entity> sharedEntity(new Entity());
		// With shared pointer we can copy
		s1 = sharedEntity;
	}
	// Here, when s1 gets destroyed is when sharedEntity will be destroyed
}

	// weak_ptr example
{
	std::weak_ptr<Entity> w1;
	{
		std::shared_ptr<Entity> sharedEntity = std::make_shared<Entity>();

		w1 = sharedEntity;
		// The weak pointer is destroyed here
	}
}

}

