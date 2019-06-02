// To check out what the preprocessor is actually doing compile with -E

// this includes a lot of code
// #include <iostream>

#define INTEGER int

// if it's 1, it while be in the generated code
#if 1
INTEGER Multiply(int a, int b)
{
	INTEGER result = a*b;
	return result;
// ridicilouis include
#include "EndBrace.h"
#endif
