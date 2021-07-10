# Beyond Just "Showing" Output

While you can use the PX macros to easily create some output
there is actually another option along the lines of
automated testing.

### The TDD cousin of showing a values

The header file `pxt.h` , as provided with this exercise
actually defines two more.

When reading on be aware of the following:

-   Do not strive to UNDERSTAND what's going in the
    implementation of the new macros.
-   **For the next three days it fully suffices to
    understand how they are meant to be used.**
-   At the end of that training we'll give these macros a
    closer look.
-   And even improve them by applying some C++ features you
    have learned.
-   Currently the implementation suffices for the purpose.
-   Making it "nicer" (= more readable, more maintainable
    ...) can wait bit.

#### What is the intended use?

The difference between `PX` and `PX_` is that the latter has
an additional argument

-   If the actual output meets the expectation nothing is
    printed.
-   If it doesn't, the actual value is shown followed by the
    expectation.
-   So we have simple TDD facility which only shows the
    "failed tests".

When the program ends a summary is printed,  how many tests
passed have run and whether there had been failed tests.

-   The macro `PN_` provides a description WHAT has been
    tested ...
-   ... shown as part of the "done" / "fail" count,

#### Time to try it

Now you may just RUN the provided code in main.cpp and look
at its output. Then look at the source code and you will
recognize this structure.

First there needs to be the test title defined:

-   Usually this goes close to the start (only the
    `#include "pxt.h"` must go before).
-   Also it needs to be outside any block, i.e. at the
    global level.

```
PN_(The Ultimate Question of Life, the Universe, and Everything)
```

Then anything can be done with `PX_` that could be done with
`PX`, only there is the need for another argument (as first
thing).

```
int const that_is_the_answer = 0x10101;
PX("42", that_is_the_answer);
```

(As you have probably already run that code at the start you
don't need to it now for a seconds time.)

Currently the program has some commented out lines for
illustrative reasons, i.e. to demonstrate the difference
between

-   just showing some output (at which a human needs to look
    and decides whether it is correct wrt. the intended
    program behavior) and
-   the TDD approach, in which the developer decides in
    advance what is the intended behavior and adds code to
    verify the expectation.

(If you have understood this you may well delete these
comments now from `main.cpp`.)

#### A more serious example 

There is one more file provided, named `bit_ops.cpp`. You
may also RUN it once before you look into the source code.

REMEMBER:\
**You cannot simply press RUN** but need either chose the
file to be compiled and run via the little down-arrow
besides the RUN button or change the default file to be run.

In the output it shows there are currently 4 passed tests
(and non failed). Here is how to proceed:

-   Locate the four functions actually holding the TDD style
    code (`shift_ops`, `bitor_ops`*,* `bitxorops`, and
    `bitand_ops`).
-   Uncomment the calls to the last three in main.
-   RUN the program once more and note there are more tests
    now, but not all pass.
-   This is because some of the expectations in `PX_` which
    are still a TODO.
-   Locate theses tests and fill in the correct expectation
    in the first macro argument.

RUN the program again to get:

```
... Demonstrating Bit Operations (TDD-Style)
=== bit_ops.cpp: 12 tests passed (OK)
```
