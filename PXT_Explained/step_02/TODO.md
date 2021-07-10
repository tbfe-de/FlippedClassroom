# Header Files for Common Functionality

Among of the core properties for easy to maintain software
and reusability is achieved by following the DRY-Principle

"Don't Repeat Yourself".

For a useful functionality implemented as a macro, like
`PX`, this means it should go inside a header file.

* * * * *

You may have heard or read that C++ provides language
features to make the use of macros obsolete. Some go as for
to say the whole C/C++ preprocessor is an anachronism.

But fact is:

* The `PX` macros uses a feature called "stringizing" which
  cannot be replaced in any way by any other language
  feature.
* The C/C++ preprocessor is the only way to store
  information textually required to be available in several
  source files in a single place.

* * * * *

## Practical Exercise

### Providing a preprocessor macro via a header file

The definition of the macro `PX` has been moved to `pxt.h`.
At the end of that exercise it will be used in two
independent `.cpp` files.

#### Checking the content of the header file

Start by looking into the header file. While it's not
strictly necessary to progress with the exercise you mad add
a comment, describing what the macro does.

Here is a proposal how it may look, feel free to
*Copy&Paste* it over to the header file.

```
/*
The macro `PX` is provided as easy mechanism for C++
learners to generate output from small demo programs.
It evaluates and shows the value of any expression,
given its type has a printable representation.
(Which is the case for most any type builtin of C++.)

Besides the evaluating (`expr`) it also shows it
textually (`#expr`). This is called "stringizing" as it
converts a piece of source code to a string literal.
That feature is ONLY available for preprocessor macros!

For easy reference which piece of code generated some
output also the file name of current translation unit and
the the line number (`__FILE__` and `__LINE__`) is made
part of the output. This requires the use of a macro too,
as if it were done in an inline function the values shown
would refer to the file and line of its definition, not
of the point of its call.
*/
```

### Using the macro to print an expression

As explained the macro PX is mainly meant for the use in
small C++ programs to develop an understanding of basic
language mechanisms.

The file `main.cpp` has been prepared with an empty `main`
function. If you have no other ideas you may put in the
following, very minimal example:
```
int const ultimate_answer = 6*7;
PX(ultimate_answer);
```

#### Printing some more values

A second example has already provided in the file
`divide_ints.cpp`. As the name suggests it is meant to
demonstrate the behavior of the division operator (`/`) when
applied to something type `int`.

> The following explanations how you compile and run `main`
  programs in different `*.cpp` files only apply to those
  who do the practical exercises on the *Coding Rooms*
  Platform and want to use the RUN button. If you are used
  to compile and run programs from a shell command you
  probably already have the required knowledge.

* You can't compile and run the program by simply clicking
  on RUN.
* Instead you need to click on the small downward pointing
  angle besides it …
* … and from the pull-down menu select the file you want
    to run.

You can also change the default file to be RUN. So, if you
repeatedly use a certain example for some time, it may be
easier to change the default. 

### Cloning one program into another one

> Like the previous step this one is more about the
  handling of Coding Rooms. When working at the command
  line making a copy can be done with the `cp` command,
  requiring no renaming afterwards.

* Make a copy of the file `divide_ints.cpp`.
* Rename the copy to `divide_floats.cpp`.
* Change the type of variables `a` and `b` to `float`.

RUN the new program.

> REMINDER for *Coding Rooms* users:\
  **Not just hit RUN** - select from the pull-down menu or
  change the default.

 ### Creating more tests

Now that you have seen how easy it is feel free to go ahead
and create more tests.
