This step will not add any new functionality but add a bunch
of type definition convenionally existing in container classes.

below tghey are spelled out in C's classic `typedef`-syntax.

Maybe, as a tiny challenge, translate them into the type aliases
syntax based on the `using` keyword introduced in C++11.

(If you just *Copy&Paste* the below lines into the class
`vf_array` this will work too, as the classic syntax to
defne types – or rather type aliases – still works.)

Implement two more member functions in class `vf_array`:

```
    …
    typedef T value_type;
    typedef std::size_t size_type;
    typedef T* iterator;
    typedef const T* const_iterator;
    …
```

Of course, also USE this types now in the places where
fomerly somthing based on `T` was used.

Note that it is somewhat hard to test for these types as
if you use the `decltype(expression)`-based tests like in
`step_00/main.cpp` you get the final types and these may
be specific for a given C++ library implementation.

Though, if instead you use direct tests based on `PT_`
you can at least test if such type aliases are present.


**REMEMBER:**\
It you test expressions with `decltype` anything "refering
to memory" (in the meaning: you might take its address)
has a reference `&` as part of its deduced type.
