#include <iostream>
#include "Log.h"


// if the declaration and definition are different, we don't get an error when compiling but when linking
// it's called an unresolved external symbol.
// it happens when the linker can't find a definition to a declaration

int main()
{
	Log("Hell is here");
}
