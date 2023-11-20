#include <SDL2/SDL.h>
#include "FrameTimer.hpp"

FrameTimer::FrameTimer()
{
}

FrameTimer::~FrameTimer()
{
}

void FrameTimer::start()
{
    _begin = SDL_GetTicks();
}

uint32_t FrameTimer::getFrametime() const
{
    return SDL_GetTicks() - _begin;
}
