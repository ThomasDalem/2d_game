#include "HUD/Draggable.hpp"

using namespace HUD;

Draggable::Draggable(int x, int y, int width, int height)
    : Interactable(x, y, width, height)
    , _isDragged(false)
{}

ComponentType Draggable::getType() const
{
    return ComponentType::DRAGGABLE;
}

bool Draggable::isDragged() const
{
    return _isDragged;
}

void Draggable::onClickDown(int x, int y)
{
    _rect.x = x;
    _rect.y = y;
    _isDragged = true;
    _isClicked = true;
}

void Draggable::onClick(int x, int y)
{
    _rect.x = x;
    _rect.y = y;
}

void Draggable::onClickUp(int x, int y)
{
    _isDragged = false;
    _isClicked = false;
}
