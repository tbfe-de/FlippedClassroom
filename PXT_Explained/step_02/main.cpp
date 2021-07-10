#include <iostream>

#define FRAGMENT 0

#if FRAGMENT == 3 || FRAGMENT == 4
#define PX(expr) ((void)(std::cout << #expr "\t-> " << (expr) << std::endl))
#endif

int main() {
#if FRAGMENT == 1
    int a = 42;
    std::cout << "the value of a is " << a << std::endl;
    a /= 7;
    std::cout << "after dividing a by 7 it has the new value " << a << std::endl;
    std::cout << "now incrementing a with prefix `++` operator yields " << ++a << std::endl;
#elif FRAGMENT == 2
    int a = 42;
    std::cout << a << std::endl;
    std::cout << (a /= 7) << std::endl;
    std::cout << ++a << std::endl;  
#elif FRAGMENT == 3 || FRAGMENT == 4
    int a = 42;
    PX(a);
    PX(a /= 7);
    PX(++a);
 #if FRAGMENT == 4
    PX(a);    
    PX(a++);
    PX(a);
 #endif
#else
 #error "FRAGMENT must have a value between `1` and `4`"
#endif
}