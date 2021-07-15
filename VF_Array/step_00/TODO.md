# Reference Tests

The class `vf_array` will have the same programming
interface as an `std::vector`, so basically the same set of
tests should work for either one.

As a starting point, the `main` program of `step_00``
provides has an extensive set of tests an `std::vector` all
will pass. Simply copy over these tests from here to the
class being developeda and change the test object
-   from `std::vector<sometype>`
-   to `vf_array<sometype, somesize>`

It's not mandatory to re-use the tests from here to test
`vf_array`. If you want to roll your own tests go ahead.
