Again we are doing "true TDD" here by first implementing the
test before the functionality is completed. Though this time
is at least partially implemented, as

-   we do not get a compile error and
-   no code is commented out.

This is the output when the program is RUN:

```
g++ main.cpp -o main
... Developing `class NamedValue` (Stream Output Test)
::: main[11]    t -->   != height: 12
::: main[15]    t -->   != height: -1
=== main.cpp: 6 tests , 2 FAILED
```

Looking in the main function line 11 and line 15 shows that
now an object of type `NamedValue` is directly handed over
as second argument to `PX_`.

**This means there needs to be an implementation of**
`operator<<` **for** `NamedValue`**s as** `PX` **and** `PX_`
**expect the argument value can be sent to a stream to get a
human readable representation.**

A closer look at into file `NamedValue.h` reveals there
actually is one at the end but it is obviously incomplete as
it does nothing at all (except returning its  first
argument).

Obviously the task now is to add an implementation to the
skeleton of `operator<<` which

-   writing the name and the value of the NamedValue
    (accessible by argument `rhs`) ...
-   ... separated by a colon and a space ...
-   ... on the output stream (accessible by argument `lhs` )