#include <iostream>
#include <string>

class Entity
{
public:
	void Print() const { std::cout << "Hello" << std::endl; }
};

// We can overload this operator
class ScopedPtr
{
private:
	Entity *m_Obj;
public:
	ScopedPtr(Entity *entity)
		: m_Obj(entity)
	{
	}

	~ScopedPtr()
	{
		delete m_Obj;
	}

	// With the overloaded operator i can use it as i wanted to 
	Entity* operator->()
	{
		return m_Obj;
	}
	// const version if we want to use it with a const pointer
	const Entity* operator->() const 
	{
		return m_Obj;
	}
};


// Other use case for knowing offset of members of struct
struct Vector3
{
	float x, y, z;
};

int main()
{
	Entity e;
	e.Print(); // When allocated on the stack i call it like this

	// if it's a pointer i can't use the dot (e.Print() ) operator
	Entity *ptr = &e;
	// ptr.Print(); // ILLEGAL

	// I have to first dereference it ( dereferencing is accessing to where the pointer is pointing )
	Entity& entity = *ptr; // dereferencing
	// now i can use the dot operator
	entity.Print();
	
	// to avoid the dereferencing line i can do this
	(*ptr).Print(); // dereferencing and the calling Print. Parentheses necessary due to order
	
	// It looks a bit clunky so we can use the arrow operator
	ptr->Print(); // ->: dereference what's on the left and then calls Print()

	ScopedPtr scpEnt= new Entity(); // How would we call the print function from ScopedPtr?
	// Solutions
	// 1 - We could make m_Obj public and from there access Print
	// 2 - Create a function in ScopedPtr that returns m_Obj but we would have to do 
	// entity.GetObject()->Print()
	
	// What if i just wanted it to be able to be used like Entity
	// I can overload the -> operator to do just that
	scpEnt->Print();

	// Offset use case
	int offset = (long)&((Vector3*)nullptr)->y;
	std::cout << offset << std::endl;
}
