// notes from https://www.youtube.com/watch?v=4CQkkPLM_s8
#include <iostream>

class CTestClass 
{
public:
    CTestClass() { std::cout << "Constructing CTestClass...\n"; }
    void method(int n) { std::cout << "Method called: " << n << "\n";}
    ~CTestClass() { std::cout << "Destroying CTestClass...\n"; }
};

float afunction(int n, float f)
{
    std::cout << "Function called with values(" << n << ", " << f << ")\n";
    return f*n;
}

int main()
{
    // most common way of calling a function
    afunction(5, 2.5);

    // we can define pointers to functions
    float(*pfunc)(int, float) = afunction;

    // with our pointer to function we can call it like this
    pfunc(12, 7.2);

    // we can also do it with methods. in c++ these are called delegates not pointers to methods
    // delegates are more complicated since we need an instance of the class to call the method

    // most common way of calling a method from a class
    CTestClass o;
    o.method(3); // I'm calling the method for the specific instance o

    // Creating delegate and calling it with the instance o
    void(CTestClass::*pmethod) (int) = &CTestClass::method;
    (o.*pmethod)(4);

    return 0;
}