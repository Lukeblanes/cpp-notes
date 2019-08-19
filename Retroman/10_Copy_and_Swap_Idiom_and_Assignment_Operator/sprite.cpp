#include <sprite.hpp>

Sprite::Sprite(char _ap)
    : m_c(_ap)
{
}

void Sprite::draw(std::ostream& out) const
{
    out << m_c;
}
