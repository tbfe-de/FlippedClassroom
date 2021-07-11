#ifndef NamedValue_H
#define NamedValue_H

#include <cstring>

class NamedValue {
    char const *name_;
    int value_;
    static
    auto strdup(char const* s) {
        return std::strcpy(new char[std::strlen(s)+1], s);
    }
public:
    NamedValue(char const* name, int value = 0)
        : name_{strdup(name)}
        , value_{value}
    {/*empty*/}
    ~NamedValue() { delete[] name_; }
    NamedValue(NamedValue const&) =delete;
    NamedValue(NamedValue&& rhs) // move c'tor
        : name_{rhs.name_}
        , value_{rhs.value_} {
        rhs.name_ = nullptr;
    }
    auto name() const { return name_; }
    auto value() const { return value_; }
    NamedValue& operator=(NamedValue&&) =delete; // move-assign
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
