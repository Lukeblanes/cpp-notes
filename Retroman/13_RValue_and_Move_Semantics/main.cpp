// Notes from https://www.youtube.com/watch?v=exCYowIIZ6s

#include <iostream>
#include <cstring>
#include <cstdio>

#define DEBUGOUT  std::cerr
#define SCREENOUT std::cout
// we have two types of output that are initially shown on screen
// we can redirect any of them to a file. 
// by doing:
// ./a.out 2> out.txt
// , we redirect the error output to a file

struct GameObject;
struct Sprite;

// ANSI escape sequence drawer
struct ANSIDraw
{
    static ANSIDraw& p()
    {
        static ANSIDraw instance(SCREENOUT);
        return instance;
    }
    void cls() const { m_out << CLS; }

    void locate(uint16_t x, uint16_t y) const 
    {
        m_out << CSI << y << ';' << x << 'H';
    }
    std::ostream& operator()(uint16_t x, uint16_t y)
    {
        locate(x, y);
        return m_out;
    }
private:
    ANSIDraw(std::ostream& out) : m_out(out) {}
    std::ostream& m_out;
    const char* CSI = "\033[";
    const char* CLS = "\033[H\033[J";

};

struct Sprite
{
    Sprite(const char* data) 
    {
        dbprint() << "Create\n";
        std::memcpy(m_data, data, 9);
    }

    Sprite(const Sprite& other)
        : Sprite(other.m_data)
    {
        dbprint() << "Copy\n";
    }

    Sprite& operator=(const Sprite& other)
    {
        dbprint() << "Assign\n";
        std::memcpy(m_data, other.m_data, 9);
        return *this;
    }

    std::ostream& dbprint() const
    {
        DEBUGOUT << "[SPR]: ";
        return DEBUGOUT;
    }

    void draw(uint16_t x, uint16_t y) const 
    {
        const char* d = m_data;
        ANSIDraw& draw = ANSIDraw::p();
        draw(x, y     ) << d[0] << d[1] << d[2];
        draw(x, y + 1 ) << d[3] << d[4] << d[5];
        draw(x, y + 2 ) << d[6] << d[7] << d[8];

    }
private:
    char m_data[9];
};

struct GameObject
{
    // We add a Constructor and assignment operator with Rvalue reference
    // in the Rvalue versions, we don't have to copy, just "steal"

    GameObject(const char data[9], uint16_t x = 1, uint16_t y = 1)
        : m_id(gid++), m_x(x), m_y(y), m_s(nullptr)
    {
        dbprint() << "Create\n";
        m_s = new Sprite(data);
    }

    // This new constructor is called Move Constructor.
    // the other that is passed, at some point  will be destroyed, 
    // so we can't leave both pointing to the same Sprite.
    // To solve this we make other.m_s point to nullptr so that it doesn't
    // destroy the sprite when other is destroyed.
    GameObject(GameObject&& other)
        : m_id(gid++), m_x(other.m_x), m_y(other.m_y), m_s(other.m_s)
    {
        dbprint() << "Move from GO_" << other.m_id << "\n";
        other.m_s = nullptr;
    }

    GameObject(const GameObject& other)
        : m_id(gid++), m_x(other.m_x), m_y(other.m_y), m_s(nullptr)
    {
        dbprint() << "Copy from GO_" << other.m_id << "\n";
        if (other.m_s)
            m_s = new Sprite(*other.m_s);
    }

    // we change our assignment operator to const reference but now we have to add a fix
    // this is to prevent ambiguity between the rvalue assignment operator
    GameObject& operator=(const GameObject& other)
    {
        dbprint() << "Assign from GO_" << other.m_id << "\n";

        // Fix to use const reference
        GameObject other_aux(other);

        std::swap(m_s, other_aux.m_s);
        // std::swap(m_x, other.m_x);
        // std::swap(m_y, other.m_y);
        return *this;
    }

    GameObject& operator=(GameObject&& other)
    {
        dbprint() << "Move Assign from GO_" << other.m_id << "\n";
        std::swap(m_s, other.m_s);
        // std::swap(m_x, other.m_x);
        // std::swap(m_y, other.m_y);
        return *this;
    }

    void draw() const
    {
        if (m_s) 
            m_s->draw(m_x, m_y);
    }

    std::ostream& dbprint() const
    {
        DEBUGOUT << "[GO_"<< m_id << "]: ";
        return DEBUGOUT;
    }

    ~GameObject()
    {
        DEBUGOUT << "Destroy\n";
        if (m_s)
        {
            delete m_s;
            m_s = nullptr;
        }
    }
private:
    static uint16_t gid;
    // Definition of static: whatever is declared as static must exist during the whole execution of the program.
    // it exists before main is called and destroyed after main is executed. 
    // it's like a global variable but can only be accessed through GameObject

    uint16_t m_id = 0, m_x = 1, m_y = 1;
    Sprite *m_s = nullptr;
};

// if we removed this, it would never be created. 
uint16_t GameObject::gid = 0;

void old_swap(GameObject& a, GameObject& b)
{
    // 1. GameObject tmp(a); does:
    // [GO_2]: Copy from GO_0
    // [SPR]: Create
    // [SPR]: Copy
    GameObject tmp(a); 

    // 2. a = b; does:
    // [GO_3]: Copy from GO_1
    // [SPR]: Create
    // [SPR]: Copy
    // [GO_0]: Assign from GO_3
    // Destroy

    // GO_3 is the passed by value copy b that is passed to GameObject::operator=
    // then it's assigned to GO_0 (a) and when the scope is left, the object with
    // the swapped values we don't need is destroyed
    a = b;

    // 3. b = tmp; does:
    // [GO_4]: Copy from GO_2
    // [SPR]: Create
    // [SPR]: Copy
    // [GO_1]: Assign from GO_4
    // Destroy

    // Same process as 2
    b = tmp;

    // 4. Once the scope is left tmp is deleted
}

void swap(GameObject& a, GameObject& b)
{
    // in the old_swap, even though we have our move assignment implemented, 
    // we are passing lvalues so it isn't called. 

    // using a static cast is ambiguous so we change our copy constructor 
    // to pass a const reference
    GameObject tmp(static_cast<GameObject&&>(a)); 
    a = static_cast<GameObject&&>(b);
    b = static_cast<GameObject&&>(tmp);

    // static_cast is the same as using std::move. 
    /* 
    GameObject tmp(static_cast<GameObject&&>(a)); 
    a = static_cast<GameObject&&>(b);
    b = static_cast<GameObject&&>(tmp);
    */

   // std::forward is a conditional move.

    // using static_cast is for references and
    // reinterpret_cast is for pointers.

    // After implementing the rvalue assignment and move constructor
    // the std::swap will also work in a similar way to using our swap. 

}



GameObject create(uint8_t type, uint16_t x, uint16_t y)
{
    switch(type)
    {
        case 1:     return GameObject ( "####0####", x, y);
        case 2:     return GameObject ( "===- -===", x, y);
        case 3:     return GameObject ( "*-**+**-*", x, y);
        default:    return GameObject ( "(%)(%)(_)", x, y);
    }
}

int main(int argc, char **argv)
{
    GameObject a( "/-\\| |\\-/" );
    GameObject b = create(1, 4, 3);
    ANSIDraw::p().cls();
    // getchar() waits until we press enter.
    a.draw(); getchar();
    b.draw(); getchar();

    // we want to do a swap with GameObjects
    swap(a, b);
    a.draw(); getchar();
    b.draw(); getchar();

    // GameObject c ( static_cast<GameObject&&>(create(1, 4, 5)) );

    // In our initial solution, five GameObjects are created to
    // do the swap. 

    // We are doing many operations when the only thing we would need
    // to do is switch the pointer to the sprites. 

    // We are going to use rvalues which will indicate when we are dealing
    // with a temporary value and when we are dealing with something that shouldn't 
    // be modified.

    // an lvalue, is something we can assign things to or something that has a memory address we can obtain. 
    // an rvalue, is something that doesn't have a memory address, that we can't assign things to. 

    /*
    uint16_t a = 5; // OK
    a = b;          // OK
    5 = a;          // NO
     */

    // c++ also allows us to use references
    /*
    
    uint16_t a = 5;
    uint16_t& ra = a; // this would be like an alias
    ra = 6; // this will change ra and a

    const uint16_t& rb = a; // we can have constant refernces
    // this means that we have a reference to a but can't modify it. This is what usually do when passing by reference.

    // In these cases. the references are always to lvalues,
    // we can't do this:
    uint16_t& rb = 5;
    // but we can do this
    const uint16_t& rb = 5; // Since this can't modify 5. It acts like an alias to 5

    // Another thing about references is that you can't create references
    // that point to nothing. The advantage of the reference is that we don't have to check 
    // it's null so it must always point to something. 
    uint16_t& rc; // NO

    // When passing a const reference, there's no way of knowing if the value is temporary or not
    // and if it's an rvalue or not. 

    // In c++11 we can indicate, when it's a temporary object or not. 
    // So now we can make a copy if it's not temporary
    // and if it's temporary we just "redirect" without doing a copy. 

    // This indication is called rvalue references.
    uint16_t&& a; // Here we are indicating that a is a temporary value.
    
    // now we can do the following:
    uint16_t&& rra = 5;

    // Now we can indicate in our GameObject function that if it gets a temporary 
    // GameObject in the assignment operator, to "steal" the temporary object
    // and if it's not it will have to make a copy. 

     */

    // GameObject&& rG = create(1, 2, 4);

    
    return 0;
}