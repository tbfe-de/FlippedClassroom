Meanwhile the use of `NamedValue` objects increasingly looks
like if they just were variables of type `int`.

Still there are some things missing , because it is a
compile error if the following is attempted:

-   Rewrite something like `u = u + 10;`
-   into `u += 10;`

The reason is that combined assignments need to be
implemented separately sa member functions:

-   operator+=(int) to support something like u += 10;
-   operator_=_(int) to support something like u = 3;
-   etc.

It looks like a bit of work to do this for all the combined
operators so it is left up to you how many of them you want
to implement. Maybe do it just for basic arithmetic.

Of course, don't forget to add **at least one test** for
each combined assignment operator so that at the end you get
something like this:

```
g++ main.cpp -o main
... Developing `class NamedValue` (Combined Assignments Test)
=== main.cpp: 16 tests passed (OK)
```