#ifndef VF_ARRAY_H
#define VF_ARRAY_H

#include <cstddef> // std::size_t
#include <initializer_list>

template<typename T, std::size_t N>
class vf_array {
public:
    using value_type = T;
    using size_type = std::size_t;
    using iterator = T*;
    using const_iterator = T const*;
private:
    T data[N+1]; // include dummy element at end
    T* filled{&data[0]};
public:
    vf_array() =default;    
    vf_array(std::initializer_list<T> const& rhs);
    auto max_size() const
        { return N; }
    void push_back(value_type const& e)
        { *filled++ = e; }
    value_type& back()
        { return filled[-1]; }
    const value_type& back() const
        { return filled[-1]; }
    size_type size() const
        { return filled - &data[0]; }
    auto empty() const 
        { return (size() == 0); }
    iterator begin()
        { return &data[0]; }
    iterator end()
        { return filled; }
    const_iterator begin() const
        { return &data[0]; }
    const_iterator end() const
        { return filled; }
    const_iterator cbegin() const
        { return &data[0]; }
    const_iterator cend() const
        { return filled; }
    value_type& operator[](std::size_t idx)
	{ return data[idx]; }
    const value_type& operator[](std::size_t idx) const
	{ return data[idx]; }
    value_type& at(std::size_t idx)
	{ return data[(idx >= N) ? N : idx]; }
    const value_type& at(std::size_t idx) const
	{ return const_cast<vf_array*>(this)->at(idx); }
};

template<typename T, std::size_t N>
vf_array<T, N>::vf_array(std::initializer_list<T> const& rhs) {
    for (auto const& e : rhs) {
        if (size() == max_size()) break;
        push_back(e);
    }
}

template<typename T, std::size_t N>
std::ostream& operator<<(std::ostream& lhs, vf_array<T, N>& rhs) {
    for (auto const& e : rhs) {
        lhs << e << ' ';
    }
    return lhs;
}

#endif // VF_ARRAY_H