#include "pxt.h"

int main() {
    auto answer = 42;
    PX(answer);            // show VALUE of `answer`
    PT(decltype(answer));  // show deduced TYPE
}
