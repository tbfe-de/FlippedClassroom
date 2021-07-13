#ifndef clock4_OverflowCounter_H
#define clock4_OverflowCounter_H

#include "LimitCounter.h"

namespace clock4 {
    class OverflowCounter : public LimitCounter {
        LimitCounter &next_;
        void overflow() { next_.count(); }
    public:
        OverflowCounter(int limit, LimitCounter& next)
            : LimitCounter{limit}
            , next_{next}
        {}
        void count(int s = 1);
    };

} // namespace clock4

#endif // clock4_LimitCounter_H
