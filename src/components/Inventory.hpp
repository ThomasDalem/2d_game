#ifndef INVENTORY_HPP
#define INVENTORY_HPP

#include <vector>
#include <string>
#include "Sprite.hpp"
#include "utils/Vec.hpp"
#include "items/ItemsDefs.hpp"

struct ItemSlotInfo {
    ItemID id;
    std::string name;
    entt::entity item = entt::null;
};

struct Inventory {
    std::vector<entt::entity> items;
    bool isOpen = false;
};

#endif // INVENTORY_HPP