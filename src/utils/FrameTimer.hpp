#ifndef FRAME_TIMER_HPP
#define FRAME_TIMER_HPP

#include <cstdint>

class FrameTimer {
public:
    FrameTimer();
    ~FrameTimer();

    void start();

    uint32_t getFrametime() const;

private:
    uint32_t _begin;
};

#endif // FRAME_TIMER_HPP