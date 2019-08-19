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
    // std::cerr << "GO: Copy!\n";
    if (other.m_s)
        m_s = new Sprite{other.m_s->m_c};
    m_x = other.m_x;
    m_y = other.m_y;
}

GameObject& GameObject::operator=(GameObject other)
{
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