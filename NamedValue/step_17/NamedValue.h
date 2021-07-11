#ifndef NamedValue_H
#define NamedValue_H

#include <cstring>

template<typename T>
class NamedValue {
    using value_type = T;
    char const *name_;
    value_type value_;
    static
    auto strdup(char const* s) {
        return std::strcpy(new char[std::strlen(s)+1], s);
    }
public:
    NamedValue(char const* name, value_type value = 0)
        : name_{strdup(name)}
        , value_{value}
    {/*empty*/}
    ~NamedValue() { delete[] name_; }
    NamedValue(NamedValue const&) =delete;
    auto name() const { return name_; }
    auto value() const { return value_; }
    NamedValue& operator=(NamedValue& rhs) {
        value_ = rhs.value_;
        return *this;
    }
    NamedValue& operator=(value_type value) { value_ = value; return *this; }
    NamedValue& operator+=(value_type value) { value_ += value; return *this; }
    NamedValue& operator-=(value_type value) { value_ -= value; return *this; }
    NamedValue& operator*=(value_type value) { value_ *= value; return *this; }
    NamedValue& operator/=(value_type value) { value_ /= value; return *this; }
    operator value_type() const { return value_; }
};

#include <iostream>

template<typename T>
std::ostream& operator<<(std::ostream& lhs, const NamedValue<T>& rhs) {
    lhs << rhs.name() << ':' << ' ' << rhs.value();
    return lhs;
}

#endif
