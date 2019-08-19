#include <cstdint>

// Forward declation
struct Sprite;

struct GameObject
{
    GameObject(uint8_t ap = '#');
    GameObject(uint8_t ap, uint32_t x, uint32_t y);
    GameObject(const GameObject& other);

    GameObject& operator=(GameObject other);
    ~GameObject();

    void draw(std::ostream& out) const;

private:
    Sprite *m_s = nullptr;
    uint32_t m_x = 0, m_y = 0;
};