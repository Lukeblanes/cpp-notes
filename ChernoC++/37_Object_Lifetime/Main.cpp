#include <iostream>
#include <string>

// With classes once Entity exits a scope and dies, so does x die.
class Entity
{
private:
	int x;

public: 
	Entity() 
	{
		std::cout << "Created Entity! " << a << std::endl;
	}

	~Entity()
	{
		std::cout << "Destroyed Entity! " << a << std::endl;
	}
};

// Example of not good use
int* CreateArray()
{
	int array[50]; // This gets destroyed when CreateArray finishes since it's allocated on the stack
	return array;
}

// Solution 1
int* CreateArray()
{
	int *array = new int[50]; 
	return array;
}

void FillArray(int* array) // since we pass a pointer it's not going to be deallocated
{
	// Fill Arrray
}

// We can create a class that automatically destroys itself

class ScopedPtr
{
private:
	Entity *m_Ptr;
public:
	ScopedPtr(Entity *ptr)
		: m_Ptr(ptr)
	{
	}

	~ScopedPtr()
	{
		delete m_Ptr;
	}
};

int main() 
{

	// Solution 2. Create it here and manipulate in function
	int array[50];
	FillArray(array);

	if (true) 
	{ // inside the if is a scope
	}

	{
		// this is an empty scope
		Entity e;
		// Entity e* = new Entity(); // this would have to be manually destroyed
	} // Once we leave the scope, e.~Entity is called if created on the stack

	{ // This will actually get destroyed once we leave the scope
	// The ScopedPtr object is allocated on the stack even though it wraps an object allocated on the heap
	// We are using the stack destruction to call the destroyer to destroy the wrapped entity
		ScopedPtr e(new Entity()); // explicit
		// ScopetPtr e = new Entity(); // Implicit conversion version
	}

	// Another use case for scope based destrruction is a timer. 
	// We create a timer and when it's destroyed we store the time
	// Mutex Locking is another use case.
}

