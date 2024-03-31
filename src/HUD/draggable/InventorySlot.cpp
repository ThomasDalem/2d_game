#include <iostream>
#include "InventorySlot.hpp"

using namespace HUD;

InventorySlot::InventorySlot(int x, int y, int width, int height) : Draggable(x, y, width, height)
{}

void InventorySlot::onClickDown(int x, int y)
{
    std::cout << "Clicked\n";
}

void InventorySlot::onHover(int x, int y)
{
    std::cout << "Hovering\n";
}
