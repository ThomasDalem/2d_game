#ifndef SPRITE_HPP
#define SPRITE_HPP

#include "utils/Vec.hpp"
#include "SDL/Texture.hpp"

struct Sprite {
    Vec2i pos;
    Vec2f scale;
    SDL::Texture &texture;
};

#endif // SPRITE_HPP