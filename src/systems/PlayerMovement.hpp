#ifndef PLAYER_MOVEMENT_HPP
#define PLAYER_MOVEMENT_HPP

#include <unordered_map>
#include "SDL2/SDL.h"
#include "entt.hpp"
#include "utils/Vec.hpp"

static const std::unordered_map<SDL_KeyCode, Vec2i> KEYS_DIRECTIONS = {
    {SDLK_z, {0, -1}},
    {SDLK_s, {0, 1}},
    {SDLK_q, {-1, 0}},
    {SDLK_d, {1, 0}}
};

void movePlayer(entt::registry &reg, SDL_Event &evt);
void stopPlayer(entt::registry &reg, SDL_Event &evt);

#endif // PLAYER_MOVEMENT_HPP