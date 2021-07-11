#ifndef clock2_Clock_H
#define clock2_Clock_H

#include "ChainCounter.h"

namespace clock2 {
    class Clock {
        ChainCounter hour;
        ChainCounter minute;
        ChainCounter second;
    public:
        Clock()
            : hour{24}
            , minute{60, &hour}
            , second{60, &minute}
        {} 
        auto getSeconds() const { return second.get(); }
        auto getMinutes() const { return minute.get(); }
        auto getHours() const { return hour.get(); }
        auto stepSeconds(int s = 1) { second.count(s); }
        auto stepMinutes(int s = 1) { minute.count(s); }
        auto stepHours(int s = 1) { hour.count(s); } 
    };
} // namepace clock2

#endif // clock2_Clock_H
