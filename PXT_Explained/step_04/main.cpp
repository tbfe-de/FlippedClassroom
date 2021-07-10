#include "pxt.h"

// required when the TDD style approach with `PX_` is used
PN_(The Ultimate Question of Life, the Universe, and Everything)

int main() {
    int const that_is_the_answer = 6*7;
//  PX(that_is_the_answer);         // just outputting the value with `PX`
    PX_("42", that_is_the_answer);  // TDD-style approach with `PX_`
}
