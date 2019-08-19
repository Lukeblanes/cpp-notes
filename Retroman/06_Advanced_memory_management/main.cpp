// Notes from https://www.youtube.com/watch?v=GmIsvHhM9EQ

// Start reading here.
// this is the initial way the program is
// Then i tried to provide my own solution in mine.cpp
// Then a more advanced way is shown in manual_management.cpp
#include <iostream>
#include <cstdint>
#include <iomanip>
 
// Pretty print a 2-digits hexadecimal value
void printHexVal(uint16_t val) {
   std::cout << std::hex << std::setw(2) << std::setfill('0') << val;
}
 
// Print a memory slice as raw bytes
void printRawMem(uint8_t* p, uint16_t linebytes, uint16_t lines) {
   for(uint16_t l=0; l < lines; ++l) {
      std::cout << reinterpret_cast<uint16_t*>(p) << " ";
      for(uint16_t u=0; u < linebytes; ++u) {
         printHexVal(*p);
         ++p;
         std::cout << " ";
      }
      std::cout << "\n";
   }
}
 
// A simple CGameObject Class
class CGameObject {
public:
   CGameObject(uint16_t x, uint16_t y)
      : m_x(x), m_y(y), m_id(ms_id++) {
      std::cout << "Creating CGameObject " << m_id
                << " (" << m_x << ", " << m_y << ") "
                << " at ( " << this << ", " << sizeof(*this) << ")\n";
   }
   ~CGameObject() {
      std::cout << "Destroying CGameObject " << m_id << "\n";
   }
 
private:
   static uint32_t ms_id;
   uint32_t m_id;
   uint16_t m_x, m_y;
};
 
uint32_t CGameObject::ms_id = 1;
 
// reinterpret cast is used to change from one type of pointer to another

// We've learned by looking at the output that by doing std::cout in the 
// constructor of the gameObject, we are allocating memory in the heap. 
// This can mess with out memory alignment.

// the new and delete internally does things that are unpredictable. 
// when we delete the memory still seems to be in use. A notable difference is that
// we can get around this upredicability by doing a more manual memory management

// in mine.cpp i attempt to write the same program with just one new. 

int main() {
   CGameObject *g1, *g2;
   uint8_t* p;

   std::cout << "Start\n";
   // Reserve Memory
   g1 = new CGameObject(1,2);
   g2 = new CGameObject(3,7);
   
   // Print memory
    
    // What we subtract or sum is the size of the type of the reinterpret cast
    // in this case, it's -16 bytes since uint8_t is a byte
    // if it were <CGameObject> -16, it would 16 * sizeof(CGamObject)
   p  = reinterpret_cast<uint8_t*>(g1) - 16;
   printRawMem(p, 16, 4);
   std::cout << "--------------\n";
   
   // Delete one object and print memory
   delete g2;
   printRawMem(p, 16, 4);  
   std::cout << "--------------\n";
 
   // Delete the other object and print memory again
   delete g1;
   printRawMem(p, 16, 4);
   
   return 0;
}
