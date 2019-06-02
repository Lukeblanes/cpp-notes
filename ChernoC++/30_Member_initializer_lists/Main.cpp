#include <iostream>
#include <string>

class Example
{
public:
	Example()
	{
		std::cout << "Created Entity!" << std::endl;
	}

	Example(int x)
	{
		std::cout << "Created Entity with " << x << std::endl;
	}
};


// We are going to look at ways to initialize the members of a class
class Entity 
{
private:
	std::string m_Name;
	int m_Score;
	Example m_example;
public:
	// First Method
	/*
	Entity()
	{
		m_Name = "unknown";
	}

	Entity(const std::string& name)
	{
		m_Name = name;
	}
	*/

	// Second Method
	// We are basically replacing the equals with parenthesis
	// The order has to be the same order as the order they are declared
	// With this method it's cleaner and more readable but we have to make sure
	// that all the members are in the member initializer list, if we have one of them 
	// inside the brackets, we are creating two of the type
	// We create Example when declared, and the when we assign a new Example
	Entity()
		: m_Name("unknown"), m_Score(0), m_example(Example(8))
		  {
			  // m_example = Example(8); case where Two examples are created
		  }

	Entity(const std::string& name)
		: m_Name(name), m_Score(0)
	{
	}

	const std::string& GetName() const { return m_Name; }

};

int main()
{
	Entity e0;
	std::cout << e0.GetName() << std::endl;

	std::cin.get();
}
