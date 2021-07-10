#include <iostream>

// In this example the traslation unit `other1.cpp` only requires
// information defined in the `other.h`, whatever that might be.
// According to the "idempotency strategy" it should suffice to
// include just that header, nothing more.
//
#include "other.h"

int main() {
    // ... whatever ...
    std::cout << __FILE__ << " compiles and runs" << std::endl;
}
