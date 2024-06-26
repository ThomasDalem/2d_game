#ifndef INVENTORY_ITEM_HPP
#define INVENTORY_ITEM_HPP

#include <memory>
#include "SDL/Texture.hpp"
#include "HUD/Draggable.hpp"
#include "utils/TexturesLoader.hpp"

namespace HUD
{
    class InventoryItem : public Draggable
    {
    public:
        InventoryItem(const std::shared_ptr<SDL::Texture> &texture, const RectI &rect, DragSlots &slots, int currentSlot);
        InventoryItem(const std::string &filepath, TexturesLoader &textureLoader, const RectI &rect, DragSlots &slots, int currentSlot);

        void draw(SDL::Renderer &renderer);

        virtual void onClickDown(int x, int y);
        virtual void onClick(int x, int y);

    private:
        std::shared_ptr<SDL::Texture> _texture;
    };
}

#endif // INVENTORY_ITEM_HPP
