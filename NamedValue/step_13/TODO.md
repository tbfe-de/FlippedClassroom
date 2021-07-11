In this assignment a helper `StrDupper` is introduced to
detect problems like

-   missing `delete`-s (heap space address was handed out
    but is never returned, aka. memory leaks),
-   duplicated `delete`-s (the same heap space address is
    returned more than once),
-   premature `delete`-s (some heap space address is used
    after it has returned).

In the first round only a primitive detection of memory
leaks will be implemented. Before run the program "as is"
and look at the output.

```
... Developing `class NamedValue` (Test StrDupper Helper)
::: main[49]    StrDupper::all_returned() --> 1 != true
=== main.cpp: 22 tests , 1 FAILED
```

Can you identify the problem?

-   Obviously the result of all_returned is true -- right
    now it cannot be any other value!
-   So why does it output the numeric value `1` and not the
    word `true`, as expected?
-   Any ideas how this might be fixed? (Actually there are
    two approaches.)

STOP: Only continue if you have fixed this and you get you
have fixed that:

```
... Developing `class NamedValue` (Test StrDupper Helper)
=== main.cpp: 22 tests passed (OK)
```

Now continue by implementing the TODO-s in the files

-   `StrDupper.h` and
-   `StrDupper.cpp`

Finally replace this:

-   the call to `strdup` -- the helper function in class
    `NamedValue` -- needs to become a call to
    `StrDupper::dup`.
-   the call to `delete[]` -- in the `~NamedValue` (the
    d'tor) -- needs to become a call to `StrDupper::undup`.

As there currently is no memory leak in the implementation
of `NamedValue` (hopefully!) all tests should still pass.