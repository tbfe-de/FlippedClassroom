Analyze the class design so that you finally can answer the
following questions:
-   How mny classes are there in total
-   Where is inheritance used?
-   How do the individual counters connect to each other?

Do you understand that this design with `LimitCounter` and
`OverflowCounter` the previous with `ChainCounter`is not
one is not that RADICALLY different?

Finally proof that it is ESSENTIAL here to make the member
function `count` in class `LimitCounter` virtual.
-   remove the keyword `virtual` in the header file
    `LimitCounter.h` and ALSO the keyword `override` in the
    header file `OverflowCounter`.
-   Watch one test in `main` fail. (Which one)
    What is SPECIAL in this test compared to the other ones?
-   Can you explain the problem?

Don't worry if you have problems in finding some of the
answers. Everyone of us has started in a fresh field
sometimes and felt lost and like he or she  would never
understand. That's completely normal. And in a few weeks you
will probably not understand that you didn't quite
understand this today.