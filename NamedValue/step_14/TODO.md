As the `StrDupper` already has prepared a list of addresses
it allocated, you can now improve it further. Especially you
can check now if an address handed to `StrDupper::undup`
actually came from an earlier call to `StrDupper::dup`.

Here is the strategy:

-   First understand that `StrDupper::allocated` you not
    only have the number of allocations still in use.
-   So you may also may use it as index of he next free
    entry in `StrDupper::addresses`.

Whenever `StrDupper::dup` is called to hand out a new
address can do this:

-   First check if there is still space left for another
    entry in addresses.
    -   If this is not the case throw an exception:
    -   `throw std::runtime_error{"StrDupper: space exhausted"};`
-   Then call the helper copy the string to heap space:
    -   `const auto addr = strdup(t);` (assuming `t` the
        argument received)
    -   `addresses[allocated++] = addr;`
    -   Finally return `addr` as result.

When `StrDupper::undup` is called with an address to return
it can do this:

-   Search for it in addresses from index `0` to index
    `allocated-1`.
    -   If it is not found throw an exception:
    -   `throw std::runtime_error{"StrDupper: invalid address"};`
-   If the address were found at index `idx` then "remove"
    it:
    -   `adresses[idx] = addresses[--allocated];`

IMPORTANT: As problems will be indicated with exceptions
don't forget to include the header file `<stdexcept>` in
`StrDupper.h`!

And now what? How to prove it works?

First thing is to show nothing has been broken. So what
worked before should still work, i.e. `StrDupper` will
detect a memory leak:

-   Temporarily remove (comment out) the destructor of
    NamedValue.
-   The test that all has been returned should fail now.

For further testing some code should be added so that the
exceptions thrown will not terminate the program. So the
whole block that has been already inserted earlier should
become a try-block with a catch-statement:

```
try { // ----------------------------BEGIN nested block
    ...
    ... (all tests that already existed before)
    ...
} // ----------------------------------END nested block
catch(std::exception const &ex) { PX_("", ex.what()); }
```

Note that this is a bit rough an integration in the testing
framework (more advance, professional TDD frameworks do it
better) but the idea is this:

-   Normally no exceptions should be thrown from our tests.
-   If it still happens it will be notified as a failed test
    as the expectation is the empty string.

Now the question is: how can we cause the exceptions to be
thrown? **Last and finally it boils down to deliberately
write failing code:**

-   To test the "space exhausted" case we can simply reduce
    `MAX` in `StrDupper,h` to a ridiculous low value, say 3.
    -   As soon as the forth NamedValue is created the
        `StrDupper` should throw.
-   Testing the "invalid address" case is a bit more
    involved.
    -   It can be done by allowing the default version of
        the copy constructor and creating a copy of a
        NamedValue.
    -   This will cause the raw `name_` pointer to be copied
        and once the second object gets destroyed the
        `StrDupper` should throw.

A piece of code that will produce this situation will can be
a function that takes a `NamedValue` argument NOT per
reference (a typical easy error in programming) so that the
copy c'tor is required to pass the argument 

```
auto foo(NamedValue arg) {
    // body can be empty
}
```

-   Verify that the above code will NOT compile as long as
    the copy c'tor of `NamedValue` is marked =delete.
    -   This will cause the "old rules" to kick in and
        supply a copy c'tor automatically ...
-   Temporarily comment out the line where this is done.
    -   ... which then will do the wrong thing with the raw
        pointer `name_` by just copying it
    -   (i.e. what "the rule of four" aims to avoid)

To "correct" that argument of foo above could be turned into
a reference.

AND OF COURSE: The copy c'tor should then marked `=delete`
again!