To make the use of `NamedValue` objects look more like the
use of ordinary variables the operation
`NamedValue::set(int)` may be rename to
`NamedValue::operator=(int)`. 

-   As the set operation is currently implemented inside the
    class the change is straightforward there.
-   The necessary adaptation in the test code is already
    prepared in a comment.

Applying both should give you the following again:

```
g++ main.cpp -o main
... Developing `class NamedValue` (Value Assignment Test)
=== main.cpp: 6 tests passed (OK)
```