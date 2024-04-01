#include "InventoryItem.hpp"

using namespace HUD;

InventoryItem::InventoryItem(const std::shared_ptr<SDL::Texture> &texture, const RectI &rect, DragSlots &slots, int currentSlot)
    : Draggable(rect, slots, currentSlot)
    , _texture(texture)
{}

InventoryItem::InventoryItem(const std::string &filepath, TexturesLoader &textureLoader, const RectI &rect, DragSlots &slots, int currentSlot)
    : Draggable(rect, slots, currentSlot)
    , _texture(textureLoader.getTexture(filepath))
{}

void InventoryItem::draw(SDL::Renderer &renderer)
{
    const SDL_Rect rect = _rect;
    renderer.copy(*_texture, nullptr, &rect);
}

void InventoryItem::onClickDown(int x, int y)
{
    _isDragged = true;
    _isClicked = true;
}

void InventoryItem::onClick(int x, int y)
{
    _rect.x = x - _texture->getWidth() / 2;
    _rect.y = y - _texture->getHeight() / 2;
}
