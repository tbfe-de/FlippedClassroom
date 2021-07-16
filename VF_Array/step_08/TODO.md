Reconsidering the return value of the member functions `begin()`
and `end()` in the light of whether theses functions should be
allowed for a `const vf_array` it turns out you need to have
overloads:

```
class vf_array {
    …
public:
    …
    iterator begin() { return &data[0]; } // <------------- as before
    const_iterator begin() const { return &data_[0]; } // to be added
    iterator end() { return filled_; } // <---------------- as before
    const_iterator end() const { return filled_; }     // to be added
    …
};

If not anything else this will fix the problem with `operator<<`
taking the `vf_array` as a `const` reference.

Explain what the above adds and why this is important, maybe based
on that as always in TDD, you should
-   FIRST prove the problem by adding tests that FAIL.
    -   So do this **before** you add the lines marked above.
-   THEN make the above additions.
    -   Proving the added lines are effective to fix the problem.


```
…
template<typename T>
auto is_const(T&) { return "T ref"; }

template<typename T>
auto is_const(T const&) { return "const T ref"; }

int main() {
  …

  { // ------------------------------------- step_08 test
    vf_array<int, 1> v{};
    PX_("T ref", 	is_const(   *v.begin()	    ));
    PX_("const T ref", 	is_const(   *v.cbegin()	    ));
    PX_("T ref", 	is_const(   *v.end()	    ));
    PX_("const T ref", 	is_const(   *v.cend()	    ));

    const vf_array<int, 1> cv{};
    PX_("const T ref", 	is_const(   *cv.begin()	    ));
    PX_("const T ref", 	is_const(   *cv.cbegin()    ));
    PX_("const T ref", 	is_const(   *cv.end()	    ));
    PX_("const T ref", 	is_const(   *cv.cend()	    ));
  } // --------------------------------------------------
}

Explain what and how is tested above!

Also: are you aware there is already another member function
with a very similar problem?
-   Which one is it?
-   What's the little difference to the above?
-   How would the tests to whos the problem need to look like
    - HINT: you need two more `isconst`-like functions
-   Which one is it?
-   What's the little difference to the above?
-   How would the tests to whos the problem need to look like
    - HINT: you need two more `isconst`-like functions.
-   What needs to be added as a fix?






