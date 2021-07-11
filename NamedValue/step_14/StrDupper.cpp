#include "StrDupper.h"

#include <cstring>

const char* StrDupper::adresses[MAX];
std::size_t StrDupper::allocated;
 
auto StrDupper::strdup(const char *s) {
    return std::strcpy(new char[std::strlen(s)+1], s);
}

const char* StrDupper::dup(const char *const t) {
    const auto s = strdup(t);
    if (t) {
        ++allocated;
    }
    return s;
}

void StrDupper::undup(const char *t) {
    if (t) {
        --allocated;
    }
    delete[] t;
}

bool StrDupper::all_returned() {
    return (allocated == 0);
}
