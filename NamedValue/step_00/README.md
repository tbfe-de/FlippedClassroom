Note: The compilation of this project is done with `make`.
You can simple type

```
make clean all
```

to the command prompt in the console Window. Alternatively
you can set in the "Run Configuration" the above as "Custom
Command".

-   **This has already been prepared for you.**
-   So to compile the project just hit RUN as usual.

In the console window you then will see the compile commands
(first line) and the output of the program as it is run:

```
g++ main.cpp -o main
... Developing `class NamedValue` (Preparation)
=== main.cpp: 0 tests passed (OK)
```

The  `Makefile` which controls this you will never need to
change. You may load it into the editor window for
curiosity, but be careful not to change it: "Coding Rooms"
currently has a shortcoming changing TAB characters to
spaces. This will cause the `make` command to complain like
this:

```
Makefile:5: *** missing separator.  Stop.
```

(The number in between the colons may be different as it is
the number of the offending line.)

-   If this should happen you can fix it by clicking on the
    down-pointing little angle besides the RUN button and
    chose `.fixmake.c`.
-   This compiles and runs a little C program which changes
    the spaces in the Makefile back to TAB characters.

As a preparation to the exercise be sure to understand the
compilation steps, then progress to the next step: 01