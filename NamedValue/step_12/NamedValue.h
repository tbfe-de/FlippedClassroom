#ifndef NamedValue_H
#define NamedValue_H

#include <cstring>

class NamedValue {
    char name_[18];
    int value_;
public:
    NamedValue(char const* name, int value = 0)
        : value_{value} {
        auto const sz = (sizeof name_) - 1;
        std:strncpy(name_, name, sz);
        name_[sz] = '\0';
    }
    // other options to set `value_` per default to zero were
    // (2) constructor with only a single argument delegating
    // to the work to the one above:
    // NamedValue(char const* name) : NamedValue(name, 0) {}
    // (3) a constructor with only a single argument duplicating
    // ALL of the above one but setting `value_{0}` in io
    // MI-List
    // (4) Like (3) but leaving out the initialization of `value_`
    // via its MI-list, using direct member initialization
    auto name() const { return name_; }
    auto value() const { return value_; }
    NamedValue& operator=(NamedValue& rhs) {
        value_ = rhs.value_;
        return *this;
    }
    auto operator=(int value) { value_ = value; return *this; }
    auto operator+=(int value) { value_ += value; return *this; }
    auto operator-=(int value) { value_ -= value; return *this; }
    auto operator*=(int value) { value_ *= value; return *this; }
    auto operator/=(int value) { value_ /= value; return *this; }
    operator int() const { return value_; }
};

#include <iostream>

std::ostream& operator<<(std::ostream& lhs, const NamedValue& rhs) {
    lhs << rhs.name() << ':' << ' ' << rhs.value();
    return lhs;
}

#endif
