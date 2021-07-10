# Header File Best Practices

The preprocessor and header files were introduced more that
40 years ago with the C language. From that long time of
experience one outstanding rule emerged:

## Practical exercise

### Make header files idempotent

 it means: if you provide a certain functionality (or group
 of functionalities typically used together) via a header
 file that file should be sufficient and nothing else
 needed.

#### So is the header file `pxt.h` idempotent?

In case the answer isn't already obvious simply delete the
line `#include <iostream>` from `main.cpp` and look at the
error message you get.

-   Don't simply put that line back in to main.cpp.
-   There is a better place for it to go!
-   Which is it?

**NOTE:**\
Including a secondary had a file into the primary header
that needs it, makes that primary header idempotent.

#### One problem solved, a new one created?

But by solving this one problem might have created a new,
though less obvious one:

-   What if the same header file is included twice in a
    single translation unit?
-   Try it by putting in back the `#include <iostream>` into
    `main.cpp`, now that it comes from `pxt.h` too.
-   Just do be sure do the experiment twice, put it before
    and after the `#include "pxt.h"`.

As you don't get any compiler errors, there seems to be no
problem with multiple includes of the same header. But
that's only the case because `pxt.h` doesn't define anything
problematic.

**Once a header file defines a `class` it must use a
so called "include guard" (see below).**

Currently only an efficiency argument can be made in favor
of include guards:

-   Obviously the C++ compiler has no problem with seeing a
    definition of some entity more than one time.
-   At least if such multiple definitions always define
    whatever they define in the same way.
-   But obviously too it is a waste of resources to process
    one and the same information multiple times.

#### Adding an "Include Guard"

Classic header file includes guards, as were already used in
C programming work by:

-   Chose a macro with a unique name, usually somewhat
    related to the header file name or what it defines
-   Right at the start of the head of fire test whether this
    macro is defined.
-   If so, skip over all of the content of the header by
    enclosing it in a preprocessor `#if` ... `#endif`
    directives.
-   If not, i.e. if the content is processed, as first thing
    `#define` that macro (maybe empty, doesn't matter).

Now go apply the above to the file pxt.h by putting this at
the start ...

```
#ifndef PXT_H
#define PXT_H
```

... and this at the end:

```
#endif // PXT_H
```

Of course, putting `PXT_H` at the end as a comment is not
strictly necessary but depending on your editor may help to
locate the matching `#ifndef` (or #ifdef or `#if`).

You have probably seen this so often in existing header
files that it does not require much of an explanation. But
be aware of an important caveat:

-   If you have seen this in existing standard library
    headers the name of that in route God probably starts
    and ends with two underscores.
-   This is not appropriate for a header files not part of
    your C++ implementation.
-   As Mark Rose don't use names basis it has become a
    convention to reserve every miracle starting with two
    underscores for the purpose of your implementation.
-   **Using them for your own purposes may cause a collision
    with unpredictable outcome.**
-   Once more: do not do this even if you think you do the
    right thing because you have seen it so often.
-   **It is WRONG. It was always WRONG. And it will always
    be WRONG.**
-   At least as long as we have to use header files in C++
    and put their content inside and include guard.

* * * * *

### Model Solution

While it is not part of the topics covered so far the model solution also provides some files to demonstrate the problem of double inclusion with and without an include guard.

With the two demo programs provided you may want to try this:

-   First simply RUN other1.cpp and `other2.cpp` as they are.
-   Both should not cause any problem.
-   Then remove the include guard from `MyClass.h` and see what happens.
-   Of course the problem may now be solved by removing `#incude "MyClass.h"` from `other2.cpp`.
-   But the day may come when other.h does not any longer need an `#include "MyClass"`.
-   Removing this include will cause the compilation of `other2.cpp` to fail.

Trust more that 40 years of experience and best practices developed:\
**Idempotent C/C++ header files plus include guards are the optimal solution.**