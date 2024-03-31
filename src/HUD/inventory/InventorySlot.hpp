#ifndef INVENTORY_SLOT_HPP
#define INVENTORY_SLOT_HPP

#include "HUD/Interactable.hpp"
#include "utils/Color.hpp"

namespace HUD
{
    class InventorySlot : public Interactable
    {
    public:
        InventorySlot(int x, int y, int width, int height);

        ComponentType getType() const;

        void onHoverEnter();
        void onHover(int x, int y);
        void onHoverQuit();

        void draw(SDL::Renderer &renderer);

    private:
        Color _color;
    };
}

#endif // INVENTORY_SLOT_HPP