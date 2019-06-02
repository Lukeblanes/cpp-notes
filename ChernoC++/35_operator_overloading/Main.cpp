#include <iostream>
#include <string>

struct Vector2
{

	float x, y;

	Vector2(float x, float y)
		: x(x), y(y) {}

	// We add the add function 
	Vector2 Add(const Vector2& other) const
	{
		return Vector2(x + other.x, y + other.y);
		// if we want to have the implementation in the operator and here call the operator
		// we would do:
		// return *this + other;
		// or:
		// return operator+(other);
	}

	Vector2 Multiply(const Vector2& other) const
	{
		return Vector2(x * other.x, y * other.y);
	}


	// Let's create the operator overload functions
	Vector2 operator+(const Vector2& other) const
	{
		return Add(other);
	}

	Vector2 operator*(const Vector2& other) const
	{
		return Multiply(other);
	}

	// Other useful thing to overload == / !=
	
	bool operator==(const Vector2& other) const
	{
		return x == other.x && y == other.y;
	}

	bool operator!=(const Vector2& other) const
	{
		return !(*this == other);
	}
};

// this has nothing to do with vector but with output stream
std::ostream& operator<<(std::ostream& stream, const Vector2 other)
{
	stream << other.x << ", " << other.y;
	return stream;
}

int main()
{
	// Initial Situation 
	Vector2 position(4.0f, 4.0f);
	Vector2 speed(0.5f, 1.5f);

	// I want to add to result
	// To do this we create an add function
	Vector2 resultAdd = position.Add(speed);

	// we add a new powerup that we need to multiply so resulting code is something like
	Vector2 powerup(0.5f, 1.5f);
	Vector2 resultAddMul = position.Add(speed.Multiply(powerup));

	// resultAddMul starts to look a little hard to read so let's overoad + and *
	Vector2 resultOverload = position + speed * powerup;


	// a useful this to overload is the << operator to use below
	std::cout << resultOverload << std::endl;

	if(powerup == powerup)
		std::cout << powerup << std::endl;
	if(powerup != speed)
		std::cout << speed << std::endl;
}
