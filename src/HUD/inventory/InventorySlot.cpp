#include <iostream>
#include "InventorySlot.hpp"

using namespace HUD;

InventorySlot::InventorySlot(int x, int y, int width, int height)
    : Interactable(x, y, width, height)
    , _color({255, 255, 255, 0})
{}

ComponentType InventorySlot::getType() const
{
    return ComponentType::OTHER;
}

void InventorySlot::onHoverEnter()
{
    _color = {200, 200, 200, 0};
    _isHovered = true;
}

void InventorySlot::onHover(int x, int y)
{

}

void InventorySlot::onHoverQuit()
{
    _color = {255, 255, 255, 0};
    _isHovered = false;
}

void InventorySlot::draw(SDL::Renderer &renderer)
{
    renderer.drawRect(_rect, _color.r, _color.g, _color.b, _color.a);
}
