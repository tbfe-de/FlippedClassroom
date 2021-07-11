#include "pxt.h"

int main() {
    auto const &answer = 42;
    PX(answer);
    PT(decltype(answer));
}
