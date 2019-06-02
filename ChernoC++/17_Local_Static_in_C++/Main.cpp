#include <iostream>

#define LOG(x) std::cout << x << std::endl;
#define PLAYER(a) std::cout << "player -> x: " << a.x << " y: " << a.y << " speed: " << a.speed << std::endl;
#define VEC2(a) std::cout << "vec2 -> x: " << a.x << " y: " << a.y << std::endl;

// When i call this function for the first time it will create the variable but on subsequent calls, it won't creat a new variable
// in the function below, if we call it a few times we will see the value of i will increment.
void Function()
{
	// by doing this i is only visible inside this scope
	static int i = 0;
	i++;
	std::cout << i << std::endl;
}


// the function above is more or less similar to doing . . . 
int j = 0;
void Function_1()
{
	// j is visible inside and in a global scope
	j++;
	std::cout << j << std::endl;
}
// if we do it the way of Function_1, anyone can change the value of j during execution but it can't be done in the first way

// other use case is a singleton class
/*
class Singleton
{
private:
	static Singleton* s_Instance;
public:
	static Singleton& Get() { return *s_Instance; } 

	void Hello()
	{
		std::cout << "hello world" << std::endl;
	}
};

Singleton* Singleton::s_Instance = nullptr;
*/

// An alternative way to do the singleton would be with the local static
// This also looks a lot cleaner than the other way
class Singleton
{
public:
	// if we don't put static the instance would be created, returned and destroyed
	static Singleton& Get() 
	{ 
		static Singleton instance; // If it hasn't been created, it will be created and if 
					   // it's already created it won't create it again
		return instance; 
	} 

	void Hello()
	{
		std::cout << "hello world" << std::endl;
	}
};

int main() 
{
	// s_Instance.Get().Hello();
	
	Singleton s = Singleton::Get();
	s.Hello();
	Function();
	Function();
	Function();
	Function();
	Function();

	Function_1();
	j = 33;
	Function_1();
	Function_1();
	Function_1();
	Function_1();

	std::cin.get();
}

