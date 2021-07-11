#include "ChainCounter.h"

namespace clock2 {
    void ChainCounter::count(int s) {
        for (;s > 0; --s) {
            if (++count_ >= limit_) {
                count_ = 0;
                if (next_) {
                    next_->count();
                }
            }
        } 
    }
}