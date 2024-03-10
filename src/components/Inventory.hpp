#ifndef INVENTORY_HPP
#define INVENTORY_HPP

#include <vector>
#include <string>
#include "Sprite.hpp"
#include "utils/Vec.hpp"
#include "items/ItemsDefs.hpp"

struct InvItem {
    ItemID id;
    Sprite sprite;
    std::string name;
    Vec2i gridPos;
};

struct Inventory {
    std::vector<InvItem> items;
    bool isOpen = false;
};

#endif // INVENTORY_HPP