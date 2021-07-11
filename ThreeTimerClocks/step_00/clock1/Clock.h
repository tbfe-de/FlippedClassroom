#ifndef clock1_Clock_H
#define clock1_Clock_H

namespace clock1 {
    class Clock {
        int seconds_{0};
    public:
        Clock() =default;
        auto getSeconds() const { return seconds_ % 60; }
        auto getMinutes() const { return (seconds_/60) % 60; }
        auto getHours() const { return (seconds_/60) / 60; }
        void stepSeconds(int = 1);
        void stepMinutes(int s = 1) { stepSeconds(60*s); }
        void stepHours(int s = 1)  { stepMinutes(60*s); }
    };
} // namespace clock1

#endif // Clock_H
