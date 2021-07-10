While it is not part of the topics covered so far the model
solution also provides some files to demonstrate the problem
of double inclusion with and without an include guard.

With the two demo programs provided you may want to try
this:

-   First simply RUN other1.cpp and `other2.cpp` as they
    are.
-   Both should not cause any problem.
-   Then remove the include guard from `MyClass.h` and see
    what happens.
-   Of course the problem may now be solved by removing
    `#include "MyClass.h"` from `other2.cpp`.
-   But the day may come when other.h does not any longer
    need an `#include "MyClass"`.
-   Removing this include will cause the compilation of
    `other2.cpp` to fail.

Trust more than 40 years of experience and best practices
developed:\
**Idempotent C/C++ header files plus include guards are the
optimal solution.**
