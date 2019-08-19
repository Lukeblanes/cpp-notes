#include <iostream>
#include <sprite.hpp>
#include <gameobject.hpp>


GameObject::GameObject(uint8_t ap)
    : GameObject(ap, 0, 0)
{
}
    
GameObject::GameObject(uint8_t ap, uint32_t x, uint32_t y)
    : m_s(nullptr), m_x(x), m_y(y)
{
    m_s = new Sprite(ap);
}

GameObject::GameObject(const GameObject& other)
{
    std::cerr << "GO: Copy!\n";
    if (other.m_s)
        m_s = new Sprite{other.m_s->m_c};
    m_x = other.m_x;
    m_y = other.m_y;
}

// There's a difference between using {} and () for the copy constructor

// Added Assignment operator
// Assignment operators return a reference to a class so we can do:
// a = b = c = d   - equals to - a.operator=(b).operator=(c).operator=(d)

// biggest difference in copy constructor and assignment operator is that the 
// copy constructor creates a new object and copies while the assignment operator just copies.
GameObject& GameObject::operator=(GameObject other)
{
    // Example is of d = b

    // below is an initial solution to check that we don't use the assignment operator on two of the same GameObjects
    // but why do we want to check this if most of the time this won't happen

    /* 
    if (this != &other)
    {
        m_x = other.m_x;
        m_y = other.m_y;

        if (m_s)
        {
            delete m_s;
            m_s = nullptr;
        }
        if (other.m_s)
            m_s = new Sprite{*other.m_s};
    }
    */

    // the solution to this is the copy and swap idiom
    // we can change the following:
// GameObject& GameObject::operator=(const GameObject& other)
    // to:
// GameObject& GameObject::operator=(GameObject other)
    // so that there's no way this and other are the same


    // Initially when entering the function we have three objects
    // |b.0x800| |d.0x801|     (Initial objects)
    // |cb.0x802|              (Copy of object b)

    // at the end of the scope cb will be destroyed.

    // what the copy and swap idiom does is use the scope destruction to destroy 
    // the current object and store the values of other in the current object. 

    // What happens is that the values of other are stored in this and
    // the values of this are destroyed through other when the scope is left.

    std::swap(m_x, other.m_x);
    std::swap(m_y, other.m_y);
    std::swap(m_s, other.m_s);
    

    return *this;
}
GameObject::~GameObject()
{
    if(m_s)
    {
        delete m_s;
        m_s = nullptr;
    }
}

void GameObject::draw(std::ostream& out) const
{
    out << '(' << m_x << ',' << m_y<< ":\'";
    if(m_s)
        m_s->draw(out);
    out << "\')";
}