#include <iostream>
#include <string>

class Entity;
void PrintEntity(Entity* e);

void PrintEntityRef(const Entity& e);
class Entity
{
public:
	int x, y;

	Entity(int x, int y)
	{
		// if i didn't want to use a member initializer list I'd have a problem
		// since the names of the variables coincide
		// x = x // WRONG
		// the type of this is Entity*

		(*this).x = x;
		// OR
		this->x = x;
		this->y = y;

		// what if i wanted to call PrintEntity passing current instance of this object
		PrintEntity(this);

		// for this we have to dereference it
		PrintEntityRef(*this);

	}

	int GetX() const // When we put const then this changes
	{
		// In this class because of the const the type of this
		// would be const Entity*
		return x;
	}
};

void PrintEntityRef(const Entity& e)
{
	// Print
}
void PrintEntity(Entity *e)
{
	// Print
}
int main() 
{

}
