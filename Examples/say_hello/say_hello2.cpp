#include "pxt.h"

void say_hello() {
    const char greet[] = "Ei gude, wie?"; PX(greet);
}

int main() {
    say_hello();
}
