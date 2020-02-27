#include <iostream>

// Writing Random::Get() every time we want to access a function can be a bit too long
// We can remedy this by moving the function to private and creating a function that gets 
// the instance and then calls the function we moved to private.

// instead of having the instance declared inside the class and then define it 
// in a translation unit, we can move the declaration to the Get() function

// when Get() is called for the first time, instance will be instantiated and 
// subsequent times, since it's in static memory, it will just return the instance
class Random
{
    // we might want to delete other default class functions
    Random(const Random&) = delete;
public:
    static Random& Get()
    {
        static Random instance;
        return instance;
    }

    // we call the internal function get our instance first
    // this kind of indirection doesn't usually take a performance hit
    static float Float() { return Get().IFloat(); }
private:
    Random() {}

    // We move the function we want to call to private
    float IFloat() { return m_RandomGenerator; }

    float m_RandomGenerator = 0.5f;


    // static Random s_Instance;
};

// Random::s_Instance;


int main()
{
    // Old way of calling functions from singleton
    // float num = Random::Get().Float();

    std::cout << Random::Float() << "\n";

}