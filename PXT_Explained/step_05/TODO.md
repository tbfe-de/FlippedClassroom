Showing and Testing for "Types"
-------------------------------

As C++ is a Statically Type Checked Language in the following chapters many topics are related to types.

### How might a type be printed?

Usually there is not much need to show the name of a type when a program runs. Instead, the typical situation when a software developer has to deal with types are error messages. Nevertheless there are ways to print types textually at runtime.

As for the previous exercise the goal is to learn how to use the type printing feature:

-   There is one macro named `PT` which accepts any type as arguments an prints it textually.
-   Another macro named `PT_` has an additional argument allowing to specify an expectation.
-   So there is a strict symmetry to PX and PX and that suffices to use.

#### Warming up for what's coming in future exercises

The program in `main.cpp` isn't particular complicated nor overly enlightening.  You may RUN this program now and verify it gives the following output.

```
::: main.cpp[7] cptr_t --> char const*
::: main.cpp[8] decltype(greet) --> char const*
```

The main thing to take away is that user defined types obviously are just types are just type aliases.

```
typedef char const* cptr_t;
cptr greet = "hello, world";
```

#### Still, you can do something with it

You may want to try the new syntax for user defined type definitions which was introduced with C++11. Compare to the old syntax it looks a bit more like a variable or constant initialization, as the newly defined type (alias) goes left and what it stand for goes right.

```
using cptr_t = char const*;
```

You may apply that change now and RUN the program again to verify that it's output is still the same.

#### What's more in it?

When you edited the code you will surely have seen the section which is currently excluded from compilation. It was put in there to demonstrate there is more about the operations that can be done with types and also shows how they relate to what can be done with values (= use of `PT` macro vs. use of `PT` macro). As decltype will receive some more coverage later you have to wait with getting more information. (But to satisfy purely personal curiosity you may well go now, change the `#if 0` to `#if 1`.)

#### A TDD approach to learn literal suffixes

Finally, as a glimpse at how a TDD approach may be used to learn about types based on `PT_` you may look, the program `lit_suffixes.cpp`.

-   There are some lines that should suffice to show the intend.
-   But there are still a lot of `"..TODO.."`-s left for you.

(So that you don't inadvertently spoil the fun by running the program prematurely all the lines in which you should supply the correct expectations are commented out.)

The exercise is successfully solved once you get this:

```
... Associate types with their literal suffix
=== lit_suffixes.cpp: 9 tests passed (OK)
```
