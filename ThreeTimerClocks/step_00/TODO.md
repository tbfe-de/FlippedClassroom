This project defines  different ways to implement a hh:mm:ss
clock in C/C++.

Review the three solutions.

-   Which one is the easiest to understand?
-   Which one is the most "object oriented"?
-   Which ones seems to be the easiest to adapt if you want
    the clock to count days to?
-   Or days in the week (1...7) and then weeks (unlimited).

RUN the tests for all three clocks. (The simplest way is
to change the `using` directive in `main.cpp`).

Also explain this:

-   Why is it not a type error that in the constructor of
    the variant clock3 a LimitCounter reference is
    initialized with an OverflowCounter.
-   Why does one test `clock3` fails, if the member function
    `count` is not virtual.

Note: to compile the program if you comment out `virtual` in
`LimitCounter.h` you also need to comment out `override` in
`OverflowCounter.h`.

Optional:

-   If you want to implement differently staged counters
    along the line of one of these solutions feel free to do
    so.
-   Also if you want to apply the NVI-Idiom.