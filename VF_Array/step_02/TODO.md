Below is the next functionality added to `vf_array`.
-   The ability to add a value to is end ...
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

Adding the necessary left as "TBD" in `main.cpp`. (Feel
to refer back to `step_00/main.cpp` to see what may be
appropriate tests.)

**NOTE:**\
If you test with floating point values and have difficulties
writing your expectation with the same number of fractional
digits present in the result you may also want to look in
`step_00/main.cpp` how the output for floating point numbers
can be set to a defined format and precision.
