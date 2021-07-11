In this exercise the way a `NamedValue` stores its `name_`
is modified:

-   Storage space will be moved onto the heap.
-   Hence eliminating the length restriction to 17
    characters (plus the '\0' at the end)

These are the changes that basically need to be done:

-   replace the the definition `char name_[18];` with `char
    const* name_;`
-   add the following helper function as private member of
    the class.

```
class NamedValue {
    ...
    static
    char const* strdup(char const* s) {
        return std::strcpy(new char[std::strlen(s)+1], s);
    }
    ...
public:
    ...
};
```

(Note that the use of std::strcpy and std::strlen requires
to include the appropriate header file)

-   remove the current initialization in the constructor body
-   instead add the following to the MI-list (= member
    initialization list) of the constructor
    -   note the below is just a fragment to be put into the
        MI-list
    -   the existing initialization of `value_` must stay
        there as is
    -   as there are two initializers there must be
        separating comma

```
... name_{strdup(name)} ...
```

While most of this exercise is just moving around the code
shown above to the appropriate places, be sure to take some
time for analyzing the code added ...

-   THINK ABOUT WHAT IS STILL MISSING.
-   No, it's not another test but the still the code has a
    very weak point ...
-   ... you could say a serious bug ...
-   ... that is somewhat hard to test for.