While we're at the topic to assignments, we should also
think what should happen if one `NamedValue` object is
assigned to another one.

```
class NamedValue {
    ...
public:
    NamedValue& operator=(NamedValue const& rhs) {
        ...
        ... what is appropriate here ...?
        ...
        return *this; // <--- see previous exercise
    }
};
```

Considering the purpose of `NamedValue` -- which mainly is
to add a name when it is shown on output but otherwise
behave much like an `int`, the following seems to be
appropriate:

-   Assign only the `value_` ...
    -   ... from the right hand side operand of the
        assignment (represented by `rhs` above) ...
    -   ... to the the left hand side operand of the
        assignment (represented by `*this` above)
        -   though usually not necessary to be used
            explicitly, as `this->` is also the default.
-   But leave the name of the left hand side operand as it
    was.

Go and implement this ... AND ADD AN APPROPRIATE TEST
YOURSELF to finally get the confirming "all tests passed".