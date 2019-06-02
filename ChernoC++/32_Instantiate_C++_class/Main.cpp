#include <iostream>
#include <string>

// this is so we don't have to write std::string where all the strings are
using String = std::string;

class Entity
{
private:
	String m_Name;
public:
	Entity() : m_Name("Unknown") {}
	Entity(const String& name) : m_Name(name) {}

	const String& GetName() const { return m_Name; }
};

void Function()
{
	// We can't create on the stack inside a function if we want to use it outside this scope
	Entity entity = Entity("Cherno");
}

int main()
{
	// First option: Creating it on the stack
	// Entity entity; // This calls the default constructor
	// std::cout << entity.GetName() << std::endl;

	// We can also call it whit a parameter
	// Entity entity = Entity("Cherno"); // Equivalent to Entity entity("Cherno");
	//
	
	// Example, A scope can just be {} 
	Entity *e;
	{
		Entity entity("Chernobicious");
		e = &entity;
	}
	std::cout << e->GetName() << std::endl;
	
	Entity *e1;
	{
		Entity entity1 = new Entity("Chernobinious");
		e1 = entity1;
		std::cout << entity1->GetName() << std::endl;
	}
	std::cout << e1->GetName() << std::endl;


	delete e1;
}
