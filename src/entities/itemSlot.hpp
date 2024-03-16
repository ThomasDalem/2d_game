#ifndef ITEM_SLOT_HPP
#define ITEM_SLOT_HPP

#include "entt.hpp"
#include "utils/Vec.hpp"

entt::entity makeItemSlot(entt::registry &reg, const Vec2i &invPos, const Vec2i &gridPos);

#endif // ITEM_SLOT_HPP