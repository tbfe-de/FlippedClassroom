#ifndef clock3_Clock_H
#define clock3_Clock_H

#include "LimitCounter.h"
#include "OverflowCounter.h"

namespace clock3 {
    class Clock {
        LimitCounter hour;
        OverflowCounter minute;
        OverflowCounter second;
    public:
        Clock()
            : hour{24}
            , minute{60, hour}
            , second{60, minute}
        {} 
        auto getSeconds() const { return second.get(); }
        auto getMinutes() const { return minute.get(); }
        auto getHours() const { return hour.get(); }
        auto stepSeconds(int s = 1) { second.count(s); }
        auto stepMinutes(int s = 1) { minute.count(s); }
        auto stepHours(int s = 1) { hour.count(s); } 
    };
} // namepace clock3

#endif // clock2_Clock_H
