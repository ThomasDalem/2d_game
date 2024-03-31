#include <iostream>
#include "HUD/Draggable.hpp"

using namespace HUD;

Draggable::Draggable(int x, int y, int width, int height) : Interactable(x, y, width, height)
{}

ComponentType Draggable::getType() const
{
    return ComponentType::DRAGGABLE;
}

void Draggable::onClickDown(int x, int y)
{
    std::cout << "Dragging\n";
}
