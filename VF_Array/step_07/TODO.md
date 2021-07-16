Which operator would be reqired to implement so that the
following tests would work?

```
  { // ------------------------------------ step_07 tests
    vf_array<int, 1> v0{};        PX_("",	v0);
    vf_array<int, 1> v1{1, 2, 3}; PX_("1 ",	v1);
    vf_array<int, 2> v2{2, 3, 4}; PX_("2 3 ",	v2);
    vf_array<int, 3> v3{4, 5, 6}; PX_("4 5 6 ", v3);
    vf_array<int, 4> v4{5, 6, 7}; PX_("5 6 7 ", v4);
    vf_array<int, 5> v5{6, 7, 8}; PX_("6 7 8 ", v5);
    vf_array<int, 6> v6{7, 8, 9}; PX_("7 8 9 ", v6);
   } // --------------------------------------------------
```

RIGHT !!

There needs to be an implementation of `operator<<` taking
an `std::ostream` on as left-hand side and a `vf_array` as
its right-hand side operand:
-   If you need some help how such an operator looks like,
    read on.
-   Otherwise STOP READING now and try yourself … BUT in 
    case you get strange compile errors compare the way
    you defined the operator with what is shown below.

As the right hand side operand `vf_array` is a template and
the operator should work for all its possible instantiantions
it needs to be a template too:

```
template<typename T, std::size_t N>
std::ostream& operator<<(std::ostream& lhs, vf_array<T, N> &rhs) {
    /*TBD*/
    return lhs;
}
```

All right – if you landed here because you tried it yourself but got
an error messages due to defining `rhs` as a `const` reference, which
you then took out for a succesful compilation, be sure not to miss
the next step.
