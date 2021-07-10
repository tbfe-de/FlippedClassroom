#include <iostream>
#include "pxt.h"

int main() {
    float const a = 6;  PX(a);
    float const b = 7;  PX(b);
                        PX(42/a);
                        PX(42/b);
                        PX(a/b);
                        PX(b/a);
}
