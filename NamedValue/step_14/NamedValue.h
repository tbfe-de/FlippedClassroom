#ifndef NamedValue_H
#define NamedValue_H

#include <cstring>

#include "StrDupper.h"

class NamedValue {
    char const *name_;
    int value_;
public:
    NamedValue(char const* name, int value = 0)
        : name_{StrDupper::dup(name)}
        , value_{value}
    {/*empty*/}
    ~NamedValue() { StrDupper::undup(name_); }
    NamedValue(NamedValue const&) =delete;
    auto name() const { return name_; }
    auto value() const { return value_; }
    NamedValue& operator=(NamedValue& rhs) {
        value_ = rhs.value_;
        return *this;
    }
    NamedValue& operator=(int value) { value_ = value; return *this; }
    NamedValue& operator+=(int value) { value_ += value; return *this; }
    NamedValue& operator-=(int value) { value_ -= value; return *this; }
    NamedValue& operator*=(int value) { value_ *= value; return *this; }
    NamedValue& operator/=(int value) { value_ /= value; return *this; }
    operator int() const { return value_; }
};

#include <iostream>

std::ostream& operator<<(std::ostream& lhs, const NamedValue& rhs) {
    lhs << rhs.name() << ':' << ' ' << rhs.value();
    return lhs;
}

#endif
