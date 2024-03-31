#ifndef INVENTORY_SLOT_HPP
#define INVENTORY_SLOT_HPP

#include "HUD/Draggable.hpp"

namespace HUD
{
    class InventorySlot : public Draggable
    {
    public:
        InventorySlot(int x, int y, int width, int height);

        void onClickDown(int x, int y);
        void onHover(int x, int y);

    private:
        bool _isEmpty;
    };
}

#endif // INVENTORY_SLOT_HPP