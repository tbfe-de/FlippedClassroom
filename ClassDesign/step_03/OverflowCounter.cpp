#include "OverflowCounter.h"

namespace clock4 {
    void OverflowCounter::count(int s) {
        for (;s > 0; --s) {
            LimitCounter::count();
        } 
    }
} // namespace clock4

