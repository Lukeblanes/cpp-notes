#include <iostream>
#include <sprite.hpp>
#include <gameobject.hpp>


GameObject::GameObject(uint8_t ap)
    : GameObject(ap, 0, 0)
{
    // we remove this since now it's done below
    // m_s = new Sprite(ap);
}
    
// adding our new gameObject
GameObject::GameObject(uint8_t ap, uint32_t x, uint32_t y)
    : m_s(nullptr), m_x(x), m_y(y)
{
    // The initial solution below isn't great since it makes the code less mantainable.
    // whenever we change our GameObject we have to modify two different parts of the code.
    m_s = new Sprite(ap);

    // what we can do is that the more simple GameObject calls this one

    // m_x = x; // equivalent to this -> m_x.operator=(x)
    // Since it's an int it works but more complex objects,
    // it would call a constructor and then use the copy constructor

    // m_y = y;

    // in this case we would use an initializer list
    // by doing m_x(x), m_y(y), we would only call the copy constructor and
    // not the constructor and copy constructor
}

GameObject::GameObject(const GameObject& other)
{
    std::cerr << "GO: Copy!\n";
    if (other.m_s)
        m_s = new Sprite{other.m_s->m_c};
    m_x = other.m_x;
    m_y = other.m_y;
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