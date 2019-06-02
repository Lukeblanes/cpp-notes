#include <iostream>
#include <string>
#include <cstring>

struct Vector2
{
	float x, y;
};

// let's create a copyable string class, oldschool, with raw metall c++ features
class String
{
private:
	char *m_Buffer; // pointer of chars
	unsigned int m_Size; // to keep the size of the char
public:
	String(const char* string)
	{
		m_Size = strlen(string);
		m_Buffer = new char[m_Size + 1]; // +1 for \0 character
		// strcpy includes the null termination character
		memcpy(m_Buffer, string, m_Size); // params(destination, source, size)
		// memcpy doesn't guarantee that it puts the \0 character so we add it manually
		m_Buffer[m_Size] = 0;
	}

	~String()
	{
		delete[] m_Buffer;
	}

	
	// COPY CONSTRUCTOR
	// String(const String& other);

	// The default implementation would just do a shallow copy:
	// m_Buffer = other.m_Buffer,
	// m_Size = other.m_Size;
	
	// if we don't want a default copy constructor to exist for this class we would do
	// String(const String& other) = delete;
	// with this the code below, String second = string; wouldn't compile

	// Our own implementation of the copy constructor ( Deep copy )
	String(const String& other)
		: m_Size(other.m_Size)
	{
		std::cout << "COPIED" << std::endl;
		m_Buffer = new char[m_Size + 1];
		memcpy(m_Buffer, other.m_Buffer, m_Size + 1); // params(destination, source, size)
	}
	// function to modify a char of the string
	char& operator[](unsigned int index)
	{
		return m_Buffer[index];
	}

	// with this, ostream can access the members of this class as if they were their own
	friend std::ostream& operator<<(std::ostream& stream, const String& string);
};

// overload function
std::ostream& operator<<(std::ostream& stream, const String& string)
{
	stream << string.m_Buffer; // we can do this because of the declaration of the friend
	return stream;
}

// if this passes by value, it calls the copy constructor
// void PrintString ( String string)
// if we pass it by reference, it doesn't call the copy constructor. Since we don't modify the string we should use const
void PrintString (const String& string)
{
	std::cout << "PRINT:\n" <<  string << std::endl;
}

int main() 
{
	int a = 2;

	int b = a; // b and a are different variables with different memory addresses

	b = 3; // a will still be 2

	Vector2 c = { 2, 3};
	Vector2 d = c; // When we copy we still create a new memory address for d
	d.x = 5; // c.x is still 2

	// if we allocate on the heap it's something completely different
	Vector2 *e = new Vector2();
	Vector2 *f = e; // In this case I'm not copying the actual vector just the pointer
	// *e and *f are pointers pointing to the same Vector2
	f->x = 2; // This will affect e and f

	// With String classes we do some copying tests
	String string = "Cherni";
	// Since this creates a shallow copy, when we leave the scope we delete m_Buffer twice
	String second = string; // This provokes a crash in winblows, calls the copy constructor
	// since it's a shallow copy and m_Buffer is the same for both classes this modifies string and second
	second[2] = 'z'; // Once we create our own copy constructor this will behave as intended

	std::cout << string << std::endl;
	std::cout << second<< std::endl; 

	// the shallow copy just creates a new instance and copies the different members 
	// the behaviour we would want is that it creates a new pointer with the contents of where the original pointer pointed to
	// This is called a deep copy which is done with the copy constructor
	
	// Once we create our own copy constructor we will only change second
	
	PrintString(string);
	PrintString(second);

}
