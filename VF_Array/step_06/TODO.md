Add a constructor taking an std::<initializer_list<T> as
argument.

Maybe try it right now ...

... or read and look at the following code fragments and
add them were appropriate:
```
#include <initializer_list>
```

As declaration in the class:
```
vf_array(std::initializer_list<T> const& rhs);
``` 

Outside the class (as the body is not just a single line):
```
template<typename T, std::size:t N>
vf_array<T, N>::vf_array(std::initializer_list<T> const &rhs)
    /*TBD*/
}
```

As you see, one TBD is still left for you :-)

As we will provide improved testability only in the next
step, for the moment it suffices to test as follows:

```
  { // ------------------------------------ step_06 tests
    vf_array<int, 1> v0{{}};        PX("0", v0.size());
    vf_array<int, 1> v1{{1, 2, 3}}; PX("1", v1.size());
    vf_array<int, 2> v2{{2, 3, 4}}; PX("2", v2.size());
    vf_array<int, 3> v3{{4, 5, 6}}; PX("3", v3.size());
    vf_array<int, 4> v4{{5, 6, 7}}; PX("3", v4.size());
    vf_array<int, 5> v5{{6, 7, 8}}; PX("3", v5.size());
    vf_array<int, 6> v6{{7, 8, 9}}; PX("3", v6.size());
   } // --------------------------------------------------
```

**HINT:**\
You may well use the range-based `for`-loop to copy from
`rhs` to `data`, but take care not to overwrite any memory
behind the last element of `data` - the initializer list
may contain more elements as there is space for. 
