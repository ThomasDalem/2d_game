#ifndef SPRITE_HPP
#define SPRITE_HPP

#include "utils/Vec.hpp"
#include "utils/Rect.hpp"
#include "SDL/Texture.hpp"

struct Sprite {
    bool hidden;
    Vec2i pos;
    Vec2f scale;
    RectI rect;
    double angle;
    SDL_RendererFlip flip;
    SDL::Texture &texture;
};

#endif // SPRITE_HPP