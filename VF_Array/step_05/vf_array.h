#ifndef VF_ARRAY_H
#define VF_ARRAY_H

#include <cstddef> // std::size_t

template<typename T, std::size_t N>
class vf_array {
private:
    T data[N];
    T* filled{&data[0]};
public:
    
    auto max_size() const { return N; }
    void push_back(T const& e) { *filled++ = e; }
    T& back() { return filled[-1]; }
    std::size_t size() const { return filled - &data[0]; }
    auto empty() const { return (size() == 0); }
    T* begin() { return &data[0]; }
    T* end() { return filled; }
    T const* cbegin() const { return &data[0]; }
    T const* cend() const { return filled; }
};

#endif // VF_ARRAY_H
