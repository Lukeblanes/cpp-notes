#include <iostream>

struct Vector2
{
	float x, y;
};

// this is kind of like 2 vector2s together
struct Vector4
{
	// float x, y, z, w; // Initial way
	
	// way of putting them together: but this way creates an object
	// Vector2 GetA() { return Vector2; }

	// with union
	union
	{
		struct
		{
			float x, y, z, w;
		};
		struct
		{
			Vector2 a, b;
		};
		// After this union i have to ways of accessing the data
		// x, y, z, w or a and b
		// but doing it this way we know that a is equivalent to .x and .y and b .z .w
	};
};

void PrintVector2(const Vector2& vector)
{
	std::cout << vector.x << ", " << vector.y << std::endl;
}

int main()
{
	struct Union_name
	{
		union
		{
			float a;
			int b;
		};
	};

	Union_name u;
	u.a = 2.0f;
	// basically with unions when we do u.a we interpret it as a float and u.b as an int
	std::cout << u.a << ", " << u.b << std::endl;


	// Useful example
	Vector4 vec = {1.0f, 2.0f, 3.0f, 4.0f };
	// i can acces the elems as usual: vec.x = 3; vec.w = 543;
	std::cout << vec.a.x << std::endl; // x
	std::cout << vec.a.y << std::endl; // y 
	std::cout << vec.b.x << std::endl; // z
	std::cout << vec.b.y << std::endl; // w
	std::cout << vec.x << std::endl; // x
	std::cout << vec.y << std::endl; // y
	std::cout << vec.z << std::endl; // z
	std::cout << vec.w << std::endl; // w

	PrintVector2(vec.a);
	PrintVector2(vec.b);
}
