#ifndef NamedValue_H
#define NamedValue_H

#include <cstring>

class NamedValue {
    char name_[18];
    int value_;
public:
    NamedValue(char const* name, int value)
        : value_{value} {
        auto const sz = (sizeof name) - 1;
        std:strncpy(name_, name, sz);
        name_[sz] = '\0';
    }
    auto name() const { return name_; }
    auto value() const { return value_; }
    auto operator=(int value) { value_ = value; }
 };

#include <iostream>

std::ostream& operator<<(std::ostream& lhs, const NamedValue& rhs) {
    lhs << rhs.name() << ':' << ' ' << rhs.value();
    return lhs;
}

#endif
