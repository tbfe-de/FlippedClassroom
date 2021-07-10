#include "pxt.h"

int main() {
    typedef char const* cptr_t;
    cptr_t greet = "hello, world";
    PT(cptr_t);
    PT(decltype(greet));
    #if 0
    PX(greet);
    PT(decltype(*greet));
    PX(*greet);
    PT(decltype(greet[7]));
    PX(greet[7]);
    #endif
}
