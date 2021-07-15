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
};

#endif // VF_ARRAY_H
