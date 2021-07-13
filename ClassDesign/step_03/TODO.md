In this step the NVI (= Non Virtual Interface) idiom is
introduced.
-   It basically recommends member functions constituting
    the the public interface of a class should NOT be
    `virtual`
-   Instead **base classes** should provide virtual
    functions serving as kind of "extension points" in the
    base classes public functions.
-   These should not be `public` as they are meant to
    OVERWRITTEN but not to be CALLED by derived classes (nor
    from client code).

In the code provided with this example
-   in **the base class serving as base class** (there is
    only one, so it should be easy to spot) identify the
    member function used as extension point and
-   how it is overridden in the derived class.

**Be sure to understand with this change the code calling
`next_.count` must be removed from `OverflowCounter::count`
as otherwise it would be incremented twice.**

Verify that now you get:
````
... Testing the Clock (Version 4)
=== main.cpp: 7 tests passed (OK)
```

Could it be the derived class had no need any any longer to
overwrite the base class function (`LimitCounter::count`) at
all?
