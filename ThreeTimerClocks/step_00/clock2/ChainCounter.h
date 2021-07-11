#ifndef clock2_ChainCounter_H
#define clock2_ChainCounter_H

namespace clock2 {
    class ChainCounter {
        int count_{0};
        const int limit_;
        ChainCounter* const next_{nullptr};
    public:
        ChainCounter(int limit, ChainCounter* next = nullptr)
            : limit_{limit}, next_{next}
        {}
        auto get() const { return count_; }
        void count(int step = 1);
    };
}

#endif // clock2_ChainCouner