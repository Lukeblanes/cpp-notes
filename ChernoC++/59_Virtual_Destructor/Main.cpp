#include <iostream>

class Base
{
public:
	Base() { std::cout << "Base Constructor \n"; }
	virtual ~Base() { std::cout << "Base Destructor \n"; }
};

class Derived : public Base 
{
public:
	Derived() { std::cout << "Derived Constructor \n"; }
	~Derived() { std::cout << "Derived Destructor \n"; }
	// we could do new int[5] in constructor 
};

int main()
{
	Base* base = new Base();
	delete base; // Base Constructor, Base Destructor
	std::cout << "-------------------------\n";
	Derived* derived = new Derived();
	delete derived; // Base Constructor, Derived Constructor, Derived Destructor, Base Destructor

	std::cout << "-------------------------\n";
	// SITUATION BEFORE MAKING DESTRUCTOR VIRTUAL
	// the problem arises in the following situation
	// we are treating poly as if it was a base pointer but it's actually a pointer to derived 
	Base* poly = new Derived();
	// The derived constructor is not called
	// we need to call it just in case we have allocated memory in the heap in derived
	// the destructor isn't called and that memory isn't freed
	delete poly; // Base Constructor, Derived Constructor, Base Destructor.
	std::cout << "-------------------------\n";
	// SITUATION AFTER MAKING DESTRUCTOR VIRTUAL
	// if the virtual destructor is set everything is correctly destroyed
	// In this case any memory allocated on the heap in derived will be freed
	Base* poly1 = new Derived();
	delete poly1; // Base Constructor, Derived Constructor,Derived Destructor, Base Destructor.
}

