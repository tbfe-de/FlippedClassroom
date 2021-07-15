Add the member functions `size` and `empty`, doing the
obvious:
-   return the number of used elements and
-   return whether the array is empty.

That was probably a quick one, wasn't it?

You already got this?
```
```

You are even proud to have implemented `empty` by reusing
`size()` this way:
```
    auto empty() { return (size() == 0); }
```

**But wait a minute:**\
Did you consider these functions don't modify the `vf_array`
content so they should be marked `const` between the closing
round parenthesis of the argument list and the opening curly
brace of the block implementing the function?

**And to test for that!**

If you forgot to make these two member functions `const`
consider the following sequence of steps:
-   first ADD A TEST that is supposed to fail as long
    `size()` and `empty()` aren't marked `const`,
-   then DEMONSTRATE THE PROBLEM with this test while
    the functions still are not yet marked const,
    what in turn causes a compile error.
-   and finally APPLY THE FIX to the problem (by marking
    the two member functions `size()`and `empty()` as `const`.

**That way you have PROVEN the suspected problem actually
EXISTED and the modification actually FIXED it.**

NOW you can enjoy to get this:
```
```
