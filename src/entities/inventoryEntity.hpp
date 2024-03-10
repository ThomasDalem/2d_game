#ifndef INVENTORY_ENTITY_HPP
#define INVENTORY_ENTITY_HPP

#include "entt.hpp"
#include "utils/TexturesLoader.hpp"

entt::entity makeInventory(entt::registry &reg, TexturesLoader &textureLoader, uint16_t screenX, uint16_t screenY);

#endif // INVENTORY_ENTITY_HPP