#include <iostream>
#include "HUD/Draggable.hpp"

using namespace HUD;

Draggable::Draggable(int x, int y, int width, int height) : Interactable(x, y, width, height)
{}

ComponentType Draggable::getType() const
{
    return ComponentType::DRAGGABLE;
}

void Draggable::draw(SDL::Renderer &renderer)
{
    renderer.drawRect({_x, _y, _width, _height}, 200, 200, 200, 0);
}

void Draggable::onClickDown(int x, int y)
{
    std::cout << "Dragging\n";
}
