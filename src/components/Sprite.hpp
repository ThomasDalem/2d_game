#ifndef SPRITE_HPP
#define SPRITE_HPP

#include "utils/Vec.hpp"
#include "utils/Rect.hpp"
#include "SDL/Texture.hpp"

struct Sprite {
    Vec2i pos;
    Vec2f scale;
    RectI rect;
    SDL::Texture &texture;
};

#endif // SPRITE_HPP