#include <iostream>

// Practical use case of pointer to function
// by using them in an array
void action1()
{
    printf("- Cammera 1 \n");
}

void action2()
{
    printf("- Cammera 2 \n");
}

void action3()
{
    printf("- Cammera 3 \n");
}

void action4()
{
    printf("- Cammera 4 \n");
}

struct TKey2Func
{
    int key; // would be code for keyPress
    void (*pfunc)();
};

// Since this is just data we have the flexibility
// of reading it from a file if needed.
TKey2Func mapping[] = 
{
        { 1, action1 }
    ,   { 2, action2 }
    ,   { 3, action3 }
    ,   { 4, action4 }
    ,   { 0, 0} // to know when we hit the end
};

int main()
{
    while(true)
    {
        int currentKeyDown = 5; // to simulate actual key pressed
        TKey2Func *next = mapping; // Initially it's pointing to first element

        while(next->key) // while it's not 0
        {
            // this is a mantainable way of doing it
            // since we don't have to modify this part of the code
            // It's also easily extendable because if we want
            // to add a new key, we just modify mapping and add
            // the corresponding key and function
            if(currentKeyDown == next->key)
            {
                next->pfunc();
            }
            ++next;
        }
    }
}