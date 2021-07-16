#include <iostream>

#include "vf_array.h"

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
}
