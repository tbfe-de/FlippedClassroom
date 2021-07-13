#include "Clock.h"

namespace clock1 {
    void Clock::stepSeconds(int s) {
        seconds_ += s;
        seconds_ %= 24*60*60;
    }
} // namespace clock1
