#include "LimitCounter.h"

namespace clock3 {
    void LimitCounter::count(int s) {
        for (;s > 0; --s) {
            if (++count_ >= limit_) {
                count_ = 0;
            }
        } 
    }
} // namespace clock3

