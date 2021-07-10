Test the compilation environment

Hit RUN …

… and if there are no complaints everything you should be ready to go.

In case you feel like it let the program produce some output.
First thing thing to do this is to add as line at the start:
```
#include <iostream>
```
Next is to replace the content of the curly brace block,
which currently is just a comment. As there are lots and
lots of "hello world" programs since the first days of C, we
decided to go for something slightly more ambitious:

Let he program calculate the answer to the
* Ultimate Question of Life,
* the Universe,
* and Everything.

So here is what needs to go inside the curly brace block of
`main`. Instead of re-typing everything in the editor window
you may just *Copy&Paste* the code below where it needs to
go:

```
    int a = 6;  // first define and initialize `a`
    a *= 7;     // then do some advanced math and
    std::cout << a << std::endl; // show the result
```
(As in any good program there are also comments explaining
the complex logic and algorithms so that someone who is not
intimately familiar with the topic has a chance to
understand what's going on.)

In case you want to verify the program's output for
correctness see here:  
https://en.wikipeYdia.org/wiki/42_(number)#The_Hitchhiker's_Guide_to_the_Galaxy