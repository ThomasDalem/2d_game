#include "InventoryItem.hpp"

using namespace HUD;

InventoryItem::InventoryItem(const std::shared_ptr<SDL::Texture> &texture, int x, int y, int width, int height)
    : Draggable(x, y, width, height)
    , _texture(texture)
{}

InventoryItem::InventoryItem(const std::shared_ptr<SDL::Texture> &texture, const RectI &rect)
    : Draggable(rect.x, rect.y, rect.width, rect.height)
    , _texture(texture)
{}

InventoryItem::InventoryItem(const std::string &filepath, TexturesLoader &textureLoader, int x, int y, int width, int height)
    : Draggable(x, y, width, height)
    , _texture(textureLoader.getTexture(filepath))
{}

InventoryItem::InventoryItem(const std::string &filepath, TexturesLoader &textureLoader, const RectI &rect)
    : Draggable(rect.x, rect.y, rect.width, rect.height)
    , _texture(textureLoader.getTexture(filepath))
{}

void InventoryItem::draw(SDL::Renderer &renderer)
{
    const SDL_Rect rect = _rect;
    renderer.copy(*_texture, nullptr, &rect);
}

void InventoryItem::onClickDown(int x, int y)
{
    _rect.x = x;
    _rect.y = y;
    _isDragged = true;
    _isClicked = true;
}

void InventoryItem::onClick(int x, int y)
{
    _rect.x = x;
    _rect.y = y;
}
