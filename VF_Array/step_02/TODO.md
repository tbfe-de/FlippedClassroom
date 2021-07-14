==========================================================
COPY OVER the file `vf_array.h` from the previous solution
==========================================================


Below is the first functionality added to `vf_array`.
-   The ability to add something to is end ...
-   ... and to test for it.

```
class vf_array {
    // ...

public:
    // ...
    void push_back(const T& e) { /*TBD*/ }
    T& back() { return /*TBD*/ }
};
```

Also the tests are left as "TBD" in `main.cpp` but feel free
to refer back to `step_00/main.cpp` to see what is aprorpriate.

**NOTE:**\
The tests in `step_00/main.cpp` are only provided for reference.
**You do not need slavishly follow what is done there!**
Especially feel free to add more tests.

If you test with floating point numbers and have a dfficulty with
writing your expectation with the same number of factional digits
present in the result, you may also want to look in `step_00/main.cpp`
how the output for floating point numbers can be set to a defined
format and precision.

