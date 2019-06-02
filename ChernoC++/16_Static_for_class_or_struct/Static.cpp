

// This variable will only be linked internally inside this translation unit
static int s_Variable = 5;

// During the linking process if another translation unit is looking for s_Variable, it won't find it.
// If i remove the static keyword the compiler will complain because of the s_variable in main
// Multiple definition error

// If we have duplicate symbols, (This function is in main too ) we will get an unresolved symbol error.
// void Function() { }

// If we mark the function as static we will avoid the error
// because when the linker starts to link it won't find the 
// function with the static keyboard

static void Function() {}
