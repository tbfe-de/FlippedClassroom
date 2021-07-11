In this assignment you don't create anything new but rather
write code to AVOID the compiler does something it usually
does by default:

-   Check whether a `NamedValue` object can be created and
    initialized by another `NamedValue` object,
-   I.e. add the following to the tests in main.cpp:
    -   `NamedValue other{t};`
    -   (Assuming t is the `NamedValue` object.)
-   It will work but onsidering the special use case of
    `NamedValue` objects, that should not be possible.
    -   Each `NamedValue` object should get its own name at
        construction time.
    -   It should not just copy the name from another
        (already existing) `NamedValue` object.

Blocking the "copy constructor" is as simple as adding the
following line to the class:

```
class NamedValue {
    ...
public:
    NamedValue(NamedValue const&) =delete;
};
```

-   This should turn something like the following into an
    error:
    -   `NamedValue z{t};`
-   If a new NamedValue object should only start with the
    value of an existing object, the following may be used:
    -   `NamedValue z{"whatever", t);`

As the first doesn't work any longer, you cannot create a
new test for it. But maybe show with a new the latter WILL
work.