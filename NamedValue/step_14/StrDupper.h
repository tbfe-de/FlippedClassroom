#ifndef StrDupper_H
#define StrDupper_H

#include <cstddef>

class StrDupper {
    static const auto MAX = 50;
    static const char* adresses[MAX];
    static std::size_t allocated;
    static auto strdup(const char *);
public:
    static const char* dup(const char *t);
    static void undup(const char *t);
    static bool all_returned();
};

#endif // StrDupper_H
