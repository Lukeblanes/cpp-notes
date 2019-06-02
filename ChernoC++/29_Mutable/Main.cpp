#include <iostream>
#include <string>


class Entity
{
private:
	std::string m_Name;
	// practical use. We have a variable to count how many times a function was called
	mutable int m_DebugCount = 0; // by being mutable we can use it inside a const function
public:
	const std::string& GetName() const // this function const means we can't modify class members/attributes
	{
		m_DebugCount++;
		return m_Name;
	}
};

int main()
{
	const Entity e;
	e.GetName();

	// lambdas: usage of mutable
	// lambda is a sort of throwaway function you can assign to a variable
	int x = 8;
	// by default the lambda is read only so we can't modify x
	// by putting mutable, we can modify passed variables to the lambda
	auto f = [=]() mutable
	{
		x++;
		std::cout << x << std::endl;
	};
	// lambda note, = pass by value, & pass by reference

	f();
	std::cout << x << std::endl;
}
