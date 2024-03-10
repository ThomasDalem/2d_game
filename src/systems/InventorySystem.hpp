#ifndef INVENTORY_SYSTEM_HPP
#define INVENTORY_SYSTEM_HPP

#include <SDL2/SDL_events.h>
#include "entt.hpp"

void openInventory(entt::registry &reg, SDL_Event &evt);

#endif // INVENTORY_SYSTEM_HPP