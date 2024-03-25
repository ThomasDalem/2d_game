#include "Component.hpp"

using namespace HUD;

Component::Component(int x, int y, int width, int height, bool hidden)
    : _x(x)
    , _y(y)
    , _width(width)
    , _height(height)
    , _hidden(hidden)
{}

int Component::getX() const
{
    return _x;
}

int Component::getY() const
{
    return _y;
}

int Component::getWidth() const
{
    return _width;
}

int Component::getHeight() const
{
    return _height;
}

Vec2i Component::getPos() const
{
    return {_x, _y};
}

bool Component::isHidden() const
{
    return _hidden;
}

void Component::setX(int x)
{
    _x = x;
}

void Component::setY(int y)
{
    _y = y;
}

void Component::setWidth(int width)
{
    _width = width;
}

void Component::setHeight(int height)
{
    _height = height;
}

void Component::setPos(const Vec2i &pos)
{
    _x = pos.x;
    _y = pos.y;
}

void Component::setHidden(bool hidden)
{
    _hidden = hidden;
}
