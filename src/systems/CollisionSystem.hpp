#ifndef COLLISION_SYSTEM_HPP
#define COLLISION_SYSTEM_HPP

#include "entt.hpp"
#include "SDL/Renderer.hpp"

void handleCollisions(entt::registry &reg, SDL::Renderer &renderer);

#endif // COLLISION_SYSTEM_HPP
