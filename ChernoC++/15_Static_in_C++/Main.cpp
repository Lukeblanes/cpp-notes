#include <iostream>

#define LOG(x) std::cout << x << std::endl;
#define PLAYER(a) std::cout << "player -> x: " << a.x << " y: " << a.y << " speed: " << a.speed << std::endl;
#define VEC2(a) std::cout << "vec2 -> x: " << a.x << " y: " << a.y << std::endl;

// if the other variable in file static isn't static we can use it here using extern
// extern int s_Variable;

int s_Variable =5;

// If the variable in static is actually static, it won't be accessible here with extern so the compiler/linker wont find s_Variable
//

void Function()
{}

int main() 
{
	std::cout << s_Variable << std::endl;

	std::cin.get();

}

