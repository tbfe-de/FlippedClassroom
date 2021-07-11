Review the `NamedValue` again:

-   A constructor has been added.
-   But there are no member functions.

So how to test whether the correct values have been assigned
to the data members?

-   Understand if you just comment out the tests that are
    already there in main.cpp you will get compile errors!
-   Try it!

There are several options now, try them all (one after the
other, they are all meant to be applied as alternatives, not
in combination):

-   You may make the data members temporarily public by
    -   EITHER move the line starting the `public:`-part two
        lines up
    -   OR add an additional line `public:` as first thing
        in the class
    -   OR change the keyword `class` to `struct`
-   Or you may add the following line to the class:
    -   `friend int main();`
    -   This is called a "friend declaration"
    -   It can go anywhere INSIDE the curly brace block of
        the class.

```
... Developing `class NamedValue` (Constructor Test)
=== main.cpp: 2 tests passed (OK)
```

Be sure to understand that everything proposed here is only
a **temporary** measure.

-   It should give you an early experience of success.
-   With public member functions added in the next step it
    should be removed.