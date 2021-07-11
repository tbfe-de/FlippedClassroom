#ifndef StrDupper_H
#define StrDupper_H

class StrDupper {
    static const auto MAX = 50;
    static const char* adresses[MAX];
 //
 // TODO: add another static variable `allocated`
 //       as type chose something like `int` or
 //       `long` or `long long` ... it doesn'type
 //       really matter as long as it is a type
 //       that can be incremented and decremented.
 //       DO NOT FORGET you must also to DEFINE
 //       that variable in `StrDupper.cpp`  
 //
    static auto strdup(const char *);
public:
    static const char* dup(const char *t);
    static void undup(const char *t);
    static bool all_returned();
};

#endif // StrDupper_H
