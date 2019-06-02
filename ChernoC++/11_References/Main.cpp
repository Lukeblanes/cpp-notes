#include <iostream>

#define LOG(x) std::cout << x << std::endl;

void Increment(int value)
{ 
	// Since we are passing the parameter as value it's going to copy the value ( 2 )
	// into the function
	// it's like doing int value = 2;
	value++;
}

// If i actually want to affect the value in main ( a ) we can pass the reference or pointer
// look up the memory address and change the value through the memory address

void IncrementPointer(int* value)
{
	// *value++; will add and the dereference
	// dereferencing it to change the contents to where value is pointing
	// if i just do value++ I'm incrementing by 1 the memory address
	// because of the order of operators, it will add first and then dereference
	// so we will dereference first by using parentheses
	(*value)++;
}

// we can change the function so that it takes the reference so that we don't have to dereference it

void IncrementReference(int& value)
{
	// we are adding to a by using the reference
	value++;
}


int main() 
{

	int a = 5;
	int& ref = a; // in this case the ampersand is part of the type
	// we've created an alias because ref just exists in our code
	// we can now use ref as if it was a
	
	ref = 2; // for all intents and purposes ref is a

	// if we compile this code we will see that ref isn't a variable only the variable a will exist
	LOG(a);
	Increment(a);
	LOG(a);
	IncrementPointer(&a);
	LOG(a);
	IncrementReference(a);
	LOG(a);

	// Once you declare a reference you can't change what it references to. 
	
	int c = 7;
	int d = 2;
	int& ref_1 = d;

	ref_1 = c; // Here we aren't changing what it's referencing to but we are changin d to the contents of c
	// equivalent to d = c;
	//
	// for the same reason you can't declare an empty reference
	// int& ref; Error: requires an initializer
	
	// if i wanted to switch the reference I'd use a pointer
	
	int* ref_2 = &a;
	ref_2 = &c; // In this case we have changed what the pointer references to

	LOG(c);
	*ref_2 =123;
	LOG(c);
}

