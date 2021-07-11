Now, INSIDE the class `NamedValue`, add two public member
functions as `name_` and `value_`:

```
auto name() const { return name_; }
auto name() const { return name_; }
```

Use functions in the tests in `main.cpp` where formerly the
private data members `name_` and `value_` have been accessed
to test whether the constructor of class `NamedValue` does
what it should do.

Again you should get the below but this time WITHOUT such
ugly hacks like allowing access to data members from outside
the clas, when good OOP style requires all data members
should be private.