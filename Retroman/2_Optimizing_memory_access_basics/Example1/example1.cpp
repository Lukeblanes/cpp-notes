// notes from https://www.youtube.com/watch?v=tuPsUMX1fr4
#include <iostream>
#include <cstdint>

const uint32_t size = 100000000;

uint32_t values[size] = {1};

// Volatile will indicate that m_total will be accessible by any other file
volatile uint32_t m_total = 0; 

void sum() // 0.24s
{
    for (uint32_t i = 0; i< size; ++i)
    {
        m_total += values[i];
    }
}

// The way this improves is by not accessing
// m_total in the for loop. Accessing a "global"
// variable requires to store it locally and
// using a local variable is inmediate.
void sum2() // 0.05s
{
    uint32_t aux = m_total;
    for (uint32_t i = 0; i< size; ++i)
    {
        aux += values[i];
    }
    m_total = aux;
}

int main()
{
    sum();
    //sum2();
    std::cout << m_total << "\n";

    return 0;
}