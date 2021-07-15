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

It probably needs no mention to test for these directly
with the `PT_` macro. But you can also test with `decltype`
and member function calls returning these types.

**REMEMBER:**\
It you test expressions with `decltype` anything "refering
to memory" (and the meaning: you might take its address)
has a reference `&` as part of its deduced type.
