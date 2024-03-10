#ifndef PLAYER_MOVEMENT_HPP
#define PLAYER_MOVEMENT_HPP

#include <unordered_map>
#include "SDL2/SDL.h"
#include "entt.hpp"
#include "utils/Vec.hpp"
#include "SDL/Renderer.hpp"

void movePlayer(entt::registry &reg, SDL_Event &evt);
void stopPlayer(entt::registry &reg, SDL_Event &evt);
void turnPlayer(entt::registry &reg);

#endif // PLAYER_MOVEMENT_HPP