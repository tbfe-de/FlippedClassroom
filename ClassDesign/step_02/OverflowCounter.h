#ifndef clock3_OverflowCounter_H
#define clock3_OverflowCounter_H

#include "LimitCounter.h"

namespace clock3 {
    class OverflowCounter : public LimitCounter {
        LimitCounter &next_;
    public:
        OverflowCounter(int limit, LimitCounter& next)
            : LimitCounter{limit}
            , next_{next}
        {}
        void count(int step = 1) override;
    };

} // namespace clock3

#endif // clock3_LimitCounter_H