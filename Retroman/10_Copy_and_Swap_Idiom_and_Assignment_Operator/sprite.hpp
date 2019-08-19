#pragma once
#include <ostream>

struct Sprite 
{
    Sprite(char _ap = '@');

    void draw(std::ostream& out) const;
    char m_c = '@';
};