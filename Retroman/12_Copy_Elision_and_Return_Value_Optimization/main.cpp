// Notes from https://www.youtube.com/watch?v=OIh3i0mm39s 

#include <iostream>

#define DEBUGOUT std::cerr

struct GameObject;
struct Sprite;

std::ostream& operator<<(std::ostream& out, const GameObject& obj);
std::ostream& operator<<(std::ostream& out, const Sprite* sp);  

struct Sprite
{
    Sprite(char _c = '@') : c(_c) {}
    char c;
};

struct GameObject
{
    GameObject(char c = '@')
    {
        DEBUGOUT << "GO: Create[" << c << "] \n";
        s = new Sprite(c);
    }

    GameObject(const GameObject& other)
        : GameObject(other.s->c)
    {
        DEBUGOUT << "GO: Copy[" << s << "] \n";
    }

    GameObject& operator=(GameObject other)
    {
        DEBUGOUT << "GO: Assign[" << *this << "=" << other << "] \n";
        std::swap(s, other.s);
        return *this;
    }

    void setChar(char c) { if (s) s->c = c; }
    void draw(std::ostream& out) const
    {
        if (s) out << s->c;
        else   out<< "**";
    }

    ~GameObject()
    {
        DEBUGOUT << "GO: Destroy [" << *this << "] \n";
        if (s)
        {
            delete s;
            s = nullptr;
        }
    }
private:
    Sprite *s = nullptr;
};

std::ostream& operator<<(std::ostream& out, const Sprite* sp)
{
    if (sp) out << sp->c;
    else    out << "--";
    return out;
}

std::ostream& operator<<(std::ostream& out, const GameObject& obj)
{
    obj.draw(out);
    return out;
}

// Options for creating our GameObject
const GameObject& create1(char c) 
{
    static GameObject go;
    go.setChar(c);
    return go;
}

void create2(GameObject& o, char c)
{
    o.setChar(c);
}

GameObject create3(char c) 
{
    GameObject a(c);
    return a;
}

GameObject create4(char c) 
{
    return GameObject(c);
}

void swap(GameObject& a, GameObject& b)
{
    GameObject tmp(a); 
    a = b;
    b = tmp;
}

int main(int argc, char **argv)
{
    DEBUGOUT << "(1)"; GameObject a('a');
    DEBUGOUT << "(2)"; GameObject b('b');

    // Below, since the copy constructor delegates to constructor, 
    // we will first see a Create and then a Copy 
    DEBUGOUT << "(3)"; GameObject c( a );


    // This also calls the constructor first and then copies
    // looking at the c++ insights of this code, it does the following
    // GameObject d = GameObject(b)
    // This is because GameObject d is seen as an initialization and not an assignment.
    DEBUGOUT << "(4)"; GameObject d = b;

    // in this case both of them already exist. 
// GO: Create[a]
// GO: Copy[a]
// GO: Assign[b=a]
// GO: Destroy [b]
    // Since we pass by value we first create a new a, copy it, 
    // do the assignment by swaping and the old value is destroyed.
    DEBUGOUT << "(5)"; d = a; 

    // normally in our programs we would have a factory or something similar to create our
    // objects for us. We want this function to be efficient. Create3 optimizes and creates an NRVO
    
    // DEBUGOUT << "(6)"; GameObject e; create2(e, '!');
    // DEBUGOUT << "(6)"; GameObject e = create1('!');
    DEBUGOUT << "(6)"; GameObject e = create3('!');

    // this create3 is the only one that doesn't call the copy constructor
    // this is because it's a name return value optimization(NRVO)
    // it's name because what we return is named but it can become an RVO by 
    // changing create3 to create4, which is almost the same but without giving it a name.

    // the way the compiler optimizes it is by doing what create2 is doing. 

    // What RVO does is create what we return in the function on the stack where the function is called so we don't
    // have to create a copy, we just create it directly locally.

    // For RVO to work, we have to do things in a specific way.
    // - What is returned, can't be const or volatile
    // - The compiler must know at compilation time what's returned.


    // what if we want to do the following:
    DEBUGOUT << "(7)"; swap(b, e);

    // using std::swap gives same results
    DEBUGOUT << "(7)"; std::swap(b, e);


    // the added costs of the swaps have to do with the rule of fives.
    // it also has to do with new c++ features. The copy and move.
    
    // To understand copy semantics and move semantics, it is important to 
    // understand lvalue and rvalue.


    // in an expression like
    // a = 5
    // a is the lvalue
    // and 5 is an rvalue
    // this is the simple

    // we can do &a 
    // but not &5

    // in c++11 we can use rvalue references. 

    // with the rule of five there are additional copies we can do
    // and since we don't implement them, it defaults to
    // copy semantics. 



    // An implementation of swap is before main.
    std::cout << "===========================\n";
    std::cout << a << b << c << d << e << '\n';
    std::cout << "===========================\n";
    
    return 0;
}