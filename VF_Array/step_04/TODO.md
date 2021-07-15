Implement four more member functions in class `vf_array`:

-   `begin()` should **return a POINTER to** the first
    element through which th element CAN be modified.
    -   Therefore `begin()` is NOT suitable for a
        `vf_array` which itself is `const`.
-   `cbegin()` should **return a POINTER to** the first
    element through which it can NOT be modified.
    -   Therefore `cbegin()` IS suitable for a
        `vf_array` which itself is `const`.
-   `end()` should **return a POINTER behind** the last
    element matching the type of the pointer returned by
    `begin()`.
    -   Therefore what `end()` returns can be compared to
	the type `begin()` returns for equality/inequality.
-   `cend()` should **return a POINTER behind** the last
    element matching the type of the pointer returned by
    `cbegin()`.
    -   Therefore what `cend()` returns can be compared to
        what `begin()` returns for equality/inequality.

You may want to think about for a moment how the above need
to look like as member function declarations …

… or just read on and copy the following lines into class
`vf_array` (which still have some TBD-s):

```
    …
    // iterators for MODIFIABLE `vf_array`:
    T* begin() { /*TBD*/ }
    T* end() { /*TBD*/ }
    // iterators for NON-modifiable `vf_array`:
    T const* cbegin() const { /*TBD*/ }
    T const* cend() const { /*TBD*/ }
    …
```

Again: see the tests in `step_00/main.cpp` if you have no
good ideas how testing the correct behavior could be done.

* * * * *

And for those who going for the fast track and like to peek
ahead what's coming in a later step: could it be that what
we have so far already suffices for running a range-based
`for`-loop over all elements a `vf_array`?

**NOTE:**
As this will be covered in later step it's not in the model
solution of this step.
