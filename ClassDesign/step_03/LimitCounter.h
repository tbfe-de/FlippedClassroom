#ifndef clock4_LimitCounter_H
#define clock4_LimitCounter_H

namespace clock4 {
    class LimitCounter {
        int count_{0};
        const int limit_;
	    virtual void overflow();
    public:
        LimitCounter(int limit)
            : limit_{limit}
        {}
        auto get() const { return count_; }
        void count(int step = 1);
    };

} // namespace clock4

#endif // clock4_LimitCounter_H
