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
};

class AnotherClass : public Base 
{
public:
	AnotherClass () { std::cout << "Derived Constructor \n"; }
	~AnotherClass () { std::cout << "Derived Destructor \n"; }
};

int main()
{
	int a = 5; 
	double value = a; // there's an implicit conversion going on here

	// if we wanted to explicitly cast it
	double val = 6.43;
	int b = (int)val; // c-style cast

	// One example of c++ style cast
	double s = static_cast<int>(val) + 5.3; 

	// an example of c++ style cast safety since this cast gives an error during compilation
	// double s_err = static_cast<AnotherClass*>(val) + 5.3; 
	
	// if we do type punning it allows us to do it
	AnotherClass *s_err = reinterpret_cast<AnotherClass*>(&val); 

	// using c style cast can be dangerous since anything goes


	Derived* derived = new Derived();
	Base* base= derived;

	// this is related with run time type information
	AnotherClass* ac = dynamic_cast<AnotherClass*>(base);
	if (ac) // we can check if the conversion was successful
		std::cout << "succesful\n";
}

