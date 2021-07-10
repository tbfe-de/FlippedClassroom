#include <iostream>
#include "pxt.h"

int main() {
    int const a = 6;    PX(a);
    int const b = 7;    PX(b);
                        PX(42/a);
                        PX(42/b);
                        PX(a/b);
                        PX(b/a);
}
