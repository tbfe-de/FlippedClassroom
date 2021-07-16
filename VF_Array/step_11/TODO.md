`resize`-ing a `vf_array` like an `std::vector`

One aspect in which there is still a major difference between `std::vector`
and `vf_array` is that the letter initializes ALL its elements at construction
time with via their default constructor.

**Maybe even more important:**
-   If the element class has no default constructor it can not be held
    by a `vf_array`.
-   Therefore it also needs a copy assignment to be `push-back`-ed in an
    `vf_vector`.

You can demonstrate both with a helper class that gives some control output
in its constructors and the destructor:

```
class MyClass {
public:
#define SHOW_YOU_WERE_THERE\
    std::cout << __PRETTY_FUNCTION__ << std::endl;
    MyClass()                           { SHOW_YOU_WERE_THERE }
    MyClass(MyClass const&)             { SHOW_YOU_WERE_THERE }
    MyClass(MyClass&&)                  { SHOW_YOU_WERE_THERE }
    MyClass& operator=(MyClass const&)  { SHOW_YOU_WERE_THERE; return *this; }
    MyClass& operator=(MyClass&&)       { SHOW_YOU_WERE_THERE; return *this; }
    ~MyClass()                          { SHOW_YOU_WERE_THERE }
#undef SHOW_YOU_WERE_THERE
};

int main() {
    vf_array<MyClass, 3> v;
    v.push_back(MyClass{});
    std::cout << "hello!" << std::endl;
};

int main() {
    vf_array<MyClass, 3> v;
    SHOW_YOU_WERE_THERE
}

´´´

Aufgabe wie mündlich beschrieben:
Elemente von data sollen jeweils ein native char-Array der Länge sizeof T sein.
Diese sollen beim erhöhen der Größe mit `resize` per "Placement new";
Entsprechend beim Verringern der größe mit explizitem Destructor-Aufruf (  also ...~T() )

