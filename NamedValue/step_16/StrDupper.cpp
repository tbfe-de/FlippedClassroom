#include "StrDupper.h"

#include <cstring>

//
// TODO: (remember the comment in `strDupper.h`)
//
const char* StrDupper::adresses[MAX];

auto StrDupper::strdup(const char *s) {
    return std::strcpy(new char[std::strlen(s)+1], s);
}

const char* StrDupper::dup(const char *const t) {
    const auto s = strdup(t);
    if (t) {
        //
        // TODO:
        // INCREMENT the variable `allocated`
        // (or whatever you chose to name it)
        //
    }
    return s;
}

void StrDupper::undup(const char *t) {
    if (t) {
        //
        // TODO:
        // DECREMENT the variable `allocated`
        // (or however you chose to name it)
        //
    }   delete[] t;
}

bool StrDupper::all_returned() {
    //
    // TODO:
    // CHECK whether the variable `allocated` is
    // `0` and return `true` only it this is the
    // case, `false` otherwise.
    //
    return true;
}
