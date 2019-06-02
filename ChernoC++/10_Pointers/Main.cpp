#include <iostream>

#define LOG(x) std::cout << x << std::endl;

int main() 
{
	// purest pointer: by putting void we are saying that we don't care what the type is
	// 0 is not a valid memory address. It's the same as null.
	void* ptr_null = 0; // equivalent to void* ptr = NULL; // equivalent to void* ptr = nullptr;
	
	// When we declare a variable like this we allocate it on the stack
	int var = 8; 
	int * ptr = &var; // The & asks what the memory address of the variable is. ptr equals memory address of var
	// to access the data we have to dereference it. the * is the dereferencing operator
	*ptr = 10;
	LOG(var); // outputs 10. we changed the value of var through it's reference


	// We can allocate some memory on the heap. Data allocated in the heap should be deleted when we're finished with it
	char* buffer = new char[8]; // we know that a char is one byte so with this, we are allocating 8 bytes of emmory and it returns a pointer to this block of 8 bytes
	// memset fills a block of memory with data we specify memset(pointer, data, size_in_bytes)
	memset(buffer, 0, 8);

	// a double pointer would be a pointer that points to a pointer
	
	char** dbl_ptr = &buffer; // by putting & we indicate we want the memory address of buffer and not the contents which are and address to the block of 8 bytes. 

	delete[] buffer;

	// POINTER ARE INTEGERS THAT STORE A MEMORY ADDRESS

	std::cin.get();
}

