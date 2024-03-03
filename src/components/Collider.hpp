#ifndef COLLIDER_HPP
#define COLLIDER_HPP

#include <vector>
#include "utils/Vec.hpp"

struct Collider
{
    std::vector<Vec2d> vertices;
    bool display;
};


#endif // COLLIDER_HPP