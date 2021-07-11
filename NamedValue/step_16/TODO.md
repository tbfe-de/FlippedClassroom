Replace the current raw pointer with an `std::unique_ptr<char[]>`

Here is what has to change:

-   The definition `char const *name_;` must become `std::unique_ptr<char[]> name_;`
-   The initialization cannot any longer take place fully in the MI-list.

Here is the full solution:

```
class NamedValue {
    ...
public:
    NamedValue(char const* name, int value = 0)
        : name_{std::make_unique<char[]>{std::strlen(name)+1}}
        , value_{value} {
        std::strcpy(name_.get(), name);
    }
    ...
}
```

Take your time to analyze the code above before you Copy&Paste it into the class `NamedValue`!

As an alternative with better readability you may consider use a  helper function `init_name` as shown below:

```
class NamedValue {
    ...
    static auto init_name(const char* nm) {
        auto const sz = std::strlen(nm) + 1;
        auto nptr = std::make_unique<char[]>(sz);
        std::strcpy(nptr.get(), nm);
        return nptr;
    }
    ...
public:
    NamedValue(char const* name, int value)
        : name_{init_name(name)}
        , value_{value}
    {/*empty*}
    ...
}
```

But now comes the fun part: You can remove everything in `NamedValue` that once was put in to care for properly handling the raw pointer name_:

-   Nothing left to do in the destructor.
-   Default version of move constructor suffices.
-   Same for move assignment.

Also note that the copy constructor is automatically deleted as the fact that `NamedValue` now has a data member which is "move only" it automatically becomes "move only" itself.

-   Nevertheless you may leave the `=delete` of the copy c'tor for in the class definition clarity.

The only drawback is that the `StrDupper` isn't any longer watching over the proper handling of the pointer. But it also isn't so necessary any longer as the `std::unique_ptr` is easy enough to handle anyway, compared to raw pointers.

* * * * *

If you are interested in learning how a helper like the StrDupper can be improved further: there will be a separate line of step by step exercises dealing with that topic.