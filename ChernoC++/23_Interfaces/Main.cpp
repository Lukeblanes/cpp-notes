#include <iostream>
#include <string>


class Printable
{
public:
	virtual std::string GetClassName() = 0;
};

class Entity : public Printable
{
public:
	virtual std::string GetName() { return "Entity"; }
	// to make it pure virtual we remove any implementation and brackets and add = 0
	// virtual std::string GetName() = 0; // the = 0 is what makes a pure virtual function 
	// a pure virtual function has to be implemented by any child class that derives from this class
	
	std::string GetClassName() override { return "Entity"; }
};

class Player : public Entity // we don't have to specify that it inherits from printable but it can be done
{
private:
	std::string m_Name;
public:
	Player(const std::string& name)
		: m_Name(name) {}

	std::string GetName() override { return m_Name; }
	// this is a valid subclass because we provide an implementation to the pure virtual function of the interface
	std::string GetClassName() override { return "Player"; }
	
};

// with this function the player pointer will return the entity getname
void PrintName(Entity* entity)
{
	std::cout << entity->GetName() << std::endl;
}

// the only way this works is because we know that if a class is printable, it will have getClassName
// because if it's printable it has to override the pure virtual function.
void Print(Printable* obj) 
{
	std::cout << obj->GetClassName() << std::endl;
}

// if this class doesn't have GetClassName, you won't be able to instantiate it
class A : public Printable
{
	std::string GetClassName() override { return "A"; }
};

int main()
{
	Entity* e = new Entity();
	PrintName(e);
	Print(e);

	Player* p = new Player("yo");
	PrintName(p);
	Print(p);

	A* a = new A();
	Print(a);


	// the code above works fine but when we introduce polymorphism we start to get problems
	
	Entity* entity = p;
	// we expect player because the Entity pointer is pointing to a player
	// PrintName(entity);

	std::cin.get();
}
