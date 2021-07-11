To provide a move-constructor remember that its signature is
this:

```
NamedValue(NamedValue&& rhs) {
// this is your TODO
}
```

To test a call to the move constructor use this:

```
#include <utility>
...
...
...
// part of the test code
NamedValue t{"height", 123};  // two argument constructor
NamedValue t1{t}; // <--------- should still be a compile error;
NamedValue t2{std::move(t)}; // this will use the move (if implemented)
```