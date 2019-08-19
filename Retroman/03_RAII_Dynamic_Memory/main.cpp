// notes from https://www.youtube.com/watch?v=hOAn9VQdNok 
#include <iostream>
#include <cstdint>

class CGameObject
{
public:
    CGameObject(const std::string& name) 
    :   m_name(name)
    {
        std::cout << "Creating game object " << m_name << "\n";
    }

    ~CGameObject() 
    {
        std::cout << "Destroying game object " << m_name << "\n";
    }
private:
    std::string m_name;
};

/*
the main idea behind the RAII class is to encapsulate
the object in our CGameResource which will deal with the 
memory management of the class when creating or destroying the object. 
We initialize CGameResource on the stack and when it leaves 
the current scope, the destructor is called and frees the
reserved memory
 */
class CGameResource
{
public:
    CGameResource(const std::string& name)
        : m_obj(nullptr)
    {
        init(name);
    }

    ~CGameResource()
    {
        if(m_obj)
        {
            delete m_obj;
            m_obj = nullptr;
        }

    }

    void init(const std::string& name)
    {
        m_obj = new CGameObject(name);
    }

    CGameObject *p() { return m_obj; }

private:
    CGameObject *m_obj;
};


void input()        { std::cout << "input\n"; }
void render()       { std::cout << "render\n"; }
void update(bool& p)
{
    std::cout << "update\n";
    
    // pretending our application fails that provokes a memory leak
    throw std::runtime_error("run exception");   
    p = false;
}

void rungame()
{
    bool playing = true;
    // OLD WAY WITHOUT RAII
    // CGameObject *g = new CGameObject("miguel");

    // USING RAII
    CGameResource g("miguel");
    
    while (playing)
    {
        input();
        update(playing);
        render();
    }

    // used in old way
    // delete g;
}

int main()
{
    try {
        rungame();
    } catch (std::runtime_error e) {
        std::cout << e.what() << " .Abortando\n"; 
    }

    return 0;
}