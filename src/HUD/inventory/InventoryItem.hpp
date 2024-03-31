#ifndef INVENTORY_ITEM_HPP
#define INVENTORY_ITEM_HPP

#include <memory>
#include "SDL/Texture.hpp"
#include "HUD/Draggable.hpp"
#include "HUD/Image.hpp"

namespace HUD
{
    class InventoryItem : public Draggable, public Image
    {
    public:
        InventoryItem(int x, int y, int width, int height);
    };
}

#endif // INVENTORY_ITEM_HPP
