According to the "true spirit of TDD" the test this time has
been added before the functionality tested has even been
added to the class.

-   So two more tests have been added -- see in `main.cpp`
    what they are.
-   So currently it is this is what you get when RUN the
    program:

```
g++ main.cpp -o main
... Developing `class NamedValue` (Getter Test)
::: main[13]    t.value() --> 12        != -1
=== main.cpp: 4 tests , 1 FAILED
```

This is what is still missing from the class `NamedValue`
(again, of course, it should be in the public section);

```
...
auto set(int value) { value_ = value; }
...
```

But as the above is currently not implemented the line in
the test case in which the setter is used is currently
commented out. so the next steps are (in this order):

-   put a line line like the above in the class `NamedValue`
    -   RUN to see if it compiles ...
    -   ... but not yet call it from anywhere
-   Only THEN remove the comment in main to enable the call

This should turn the output into:

```
g++ main.cpp -o main
... Developing `class NamedValue` (Getter Test)
=== main.cpp: 4 tests passed (OK)
```