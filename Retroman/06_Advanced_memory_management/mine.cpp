// my initial solution to making the same program with just one new
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

   void test() 
   {
      std::cout << "this is a test -> " << m_id << "\n";
      std::cout << "ms_id reference is at -> " << &ms_id << "\n";
   }

   // With an unimplemented copy constructor, my way of doing it doesn't work.
   // CGameObject& operator=(CGameObject& test) {}
 
private:
   static uint32_t ms_id;
   uint32_t m_id;
   uint16_t m_x, m_y;
};
 
uint32_t CGameObject::ms_id = 1;

// Application Entry Point
int main() {
   CGameObject *g1, *g2;
   uint8_t* p;

   uint8_t *global;

   std::cout << "Start\n";
 
   global = new uint8_t[2*sizeof(CGameObject)]; // Reserve 2 times the size of a game Object

   // we reserved
   std::cout << "size of GameObject is " << sizeof(CGameObject) << "\n";
   std::cout << "global is pointing to " << (uint16_t *)global << "\n";

   // Reserve Memory
   g1 = reinterpret_cast<CGameObject*>(global);
   std::cout << "g1     is pointing to " << g1 << "\n";
   g2 = reinterpret_cast<CGameObject*>(global) + 1;
   std::cout << "g2     is pointing to " << g2 << "\n";


   // In the video they use emplacement new because the solution below. 
   // It works due to the default copy constructor provided by CGameObject.
   // It doesn't compile when we uncomment our own unimplemented copy constructor with = operator in the class.
   *g1 = CGameObject(1,2);
   *g2 = CGameObject(3,7);
   
   // when calling these methods, we can see that they
   g1->test();
   g2->test();
   // Print memory
   p  = reinterpret_cast<uint8_t*>(g1) - 16;
   printRawMem(p, 16, 4);
   std::cout << "--------------\n";
   
   // Delete one object and print memory
//   delete g2;
   printRawMem(p, 16, 4);  
   std::cout << "--------------\n";
 
   // Delete the other object and print memory again
//   delete g1;
   printRawMem(p, 16, 4);
   
   return 0;
}