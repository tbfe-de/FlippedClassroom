#include "OverflowCounter.h"

namespace clock3 {
    void OverflowCounter::count(int s) {
        for (;s > 0; --s) {
            LimitCounter::count();
            if (get() == 0) {
                next_.count();
            }
        } 
    }
} // namespace clock3

