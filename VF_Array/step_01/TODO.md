The functionality implemented in this step is only to
retrieve the size. For an `std::vector` this is rather a
fictitious number as it only returns the maximum value
representable by `std::size_t`.

For an `vf_array` it should return the size specified as
second template argument.

The program compiles fine, so nothing to do and continue to
the next step?

NO !!!

Review the header file `vf_array.h`
-   Obviously there is something missing, isn't it?
    -   **Hint:** what if in a larger program this header
        gets included twice, once direct and second time
        indirect via some other header?
-   And oh, while we're at it:\
    There is yet another thing missing!!\
    What could it be?
    -   **Hint:** lookup which header should be "officially"
        included whenever the type `std::size_t` is used.

Bonus question: what is the probable reason that the code
compiled without that header being included?

As – differently from an `std::vector` each `vf_array` will
have it's own maximal size, you may want to test for at
least one other size too, adding something like the
following to the main program:
```
  { // ------------------------------------ step_01 tests
    // ... as before

    vf_array<double, 3> v2{};   // <---- to be added ...
    PX_("3", v2.max_size());    // <---- ... and tested!
  } // --------------------------------------------------
```
