#include <iostream>

// In this example the traslation unit `other2.cpp` NOT only requires
// information defined in the `other.h`, whatever that might be, but
// besides needs to define `MyClass` object.
// According to the "idempotency strategy" including just the header
// `other.h` not any longer suffices, even if it is known to include
// `MyClass.h` - that needs to be included here too.
//
#include "other.h"
#include "MyClass.h"

class MyClass someObject;

int main() {
    std::cout << __FILE__ << " compiles and runs" << std::endl;
}
