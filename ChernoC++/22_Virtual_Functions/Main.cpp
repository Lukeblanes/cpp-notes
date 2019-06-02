#include <iostream>
#include <string>

class Entity
{
public:
	virtual std::string GetName() { return "Entity"; }
};

class Player : public Entity
{
private:
	std::string m_Name;
public:
	Player(const std::string& name)
		: m_Name(name) {}

	std::string GetName() override { return m_Name; }
	
};

// with this function the player pointer will return the entity getname
void PrintName(Entity* entity)
{
	std::cout << entity->GetName() << std::endl;
}
int main()
{
	Entity* e = new Entity();
	PrintName(e);

	Player* p = new Player("yo");
	PrintName(p);

	// the code above works fine but when we introduce polymorphism we start to get problems
	
	Entity* entity = p;
	// we expect player because the Entity pointer is pointing to a player
	PrintName(entity);

	std::cin.get();
}
