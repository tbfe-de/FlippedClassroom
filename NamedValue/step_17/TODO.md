Review the changes made to turn the class `NamedValue`into a
template that not only can handle `int`-s but any type that
has the required operations.
-    consider both, the class itself (i.e. file
     `NamedValue.h`)
-    the (use (or in this case test) of the class as object
     (in file `main.cpp`)

**Note that the required change is very systematic after you
have identified all usages of the type `int` where actually
any type should be allowed.**

A little bit more effort is required if if the class only
has declarations of member functions which need to be
implemented outside the class. Then the class scope which
before would have been something like this

```
NamedValue& NamedValue::operator=(NamdValue const& rhs) {
    // implementation of copy c'tor
}
```
would turn in
```
template<typename T>
NamedValue<T>& NamedValue<T>::operator=(NameValueT> const& rhs) {
    // implementation of outside of class still NEEDS to be in
    // a header file but WILL be compiled into subroutine to
    // be called with JSR/RTS at the machine level. (Unless
    // `inline` is requested.
}
```