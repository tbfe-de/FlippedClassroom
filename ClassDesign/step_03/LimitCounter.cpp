#include "LimitCounter.h"

namespace clock4 {
    void LimitCounter::overflow() {
	/*empty*/
    }
    void LimitCounter::count(int s) {
        for (;s > 0; --s) {
            if (++count_ >= limit_) {
                count_ = 0;
		overflow();
            }
        } 
    }
} // namespace clock4

