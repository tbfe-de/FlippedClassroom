#ifndef clock3_LimitCounter_H
#define clock3_LimitCounter_H

namespace clock3 {
    class LimitCounter {
        int count_{0};
        const int limit_;
    public:
        LimitCounter(int limit)
            : limit_{limit}
        {}
        auto get() const { return count_; }
        virtual void count(int step = 1);
    };

} // namespace clock3

#endif // clock3_LimitCounter_H