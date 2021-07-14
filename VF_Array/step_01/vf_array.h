template<typename T, std::size_t N>
class vf_array {
private:
    T data[N];
    T* filled{&data[0]};
public:
    auto max_size() const { return N; }
};
