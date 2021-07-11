Here comes the icing of the cake:

-   Wouldn't it be nice if he value of a `NamedValue` object
    could be accessed just by its name?
-   Instead of calling the member function `.value()` all
    the time, just use the object name (in many contexts).
-   See the tests already added to main.cpp but currently
    commented out.

YES, this is very simple: Just add a type conversion from
`NamedValue` to `int const` or `int const&`. Here is how
such a member function would be defined:

Either:

```
operator int() const { return value_; }
```

Alternatively:

```
operator int const&() const { return value_; }
```

Note the syntax is a bit unusual in that the actual return
type follows after the keyword operator.

These are the steps (following the TDD approach):

-   Implement the above (not so hard: there's just the
    return statement missing.
-   Implement only ONE of the approaches shown!
    -   Both together would cause a compile error.
    -   Of course, you may TRY both, one after the other.
-   Finally enable the currently commented-out tests in
    `main.cpp`.

Then RUN the tests and -- hopefully - end with this:

```
... Developing `class NamedValue` (Type Conversion Test)
=== main.cpp: 13 tests passed (OK)
```