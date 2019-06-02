#include <iostream>
#include <string>


class Entity
{
private:
	std::string m_Name;
	int m_Age;
public:
	// if explicit is written, the conversions seen below can't be used
	Entity(const std::string& name) 
		: m_Name(name), m_Age(-1) {}
	explicit Entity(int age) 
		: m_Name("Unknown"), m_Age(age) {}

	const std::string& GetName() const { return m_Name; }
};

void PrintEntity(const Entity& entity)
{
	// Printing
}


int main()
{
	// This is the usual way since it looks more clear
	Entity a("Cherno");
	Entity b(22);

	// we can also do this thanks to implicit conversion
	// Entity c = "Tom"; // This doesn't work since it's a const char*
	Entity c = std::string("Tom"); // here it works due to explicit conversion
	// Entity d = 25; // not valid if explicit is on
	// If explicit is set we can cast it explicitly
	Entity d = (Entity)25;

	// we can also do this
	// PrintEntity(235); // not valid when explicit is on
	// PrintEntity("Tom"); // This doesn't work since it's a const char*
	// we can wrap it in string like above:
	// PrintEntity(std::string("Tom")); 
	// or we can pass it as an Entity
	PrintEntity(Entity("Tom"));

}
