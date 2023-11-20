#ifndef PLAYER_MOVEMENT_HPP
#define PLAYER_MOVEMENT_HPP

#include "SDL2/SDL.h"
#include "entt.hpp"

void movePlayer(entt::registry &reg, uint32_t frametime, SDL_Event &evt);

#endif // PLAYER_MOVEMENT_HPP