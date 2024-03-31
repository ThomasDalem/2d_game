#include <iostream>
#include "HUD/Image.hpp"
#include "HUD/draggable/InventorySlot.hpp"
#include "InventoryLayer.hpp"

using namespace HUD;

InventoryLayer::InventoryLayer(TexturesLoader &textureLoader, int screenWidth, int screenHeight): Layer()
{
    // Inventory image
    std::unique_ptr<Image> bagImage = std::make_unique<Image>("assets/bag.png", textureLoader);
    const int centerX = (screenWidth / 2) - (bagImage->getWidth() / 2);
    const int centerY = (screenHeight / 2) - (bagImage->getHeight() / 2);
    bagImage->setPos({centerX, centerY});

    // Inventory slot
    const int bagTopPadding = 256;
    const int bagLeftPadding = 76;
    const int posX = bagImage->getX() + bagLeftPadding;
    const int posY = bagImage->getY() + bagTopPadding;
    const int slotWidth = 57;
    const int slotHeight = 57;
    std::unique_ptr<InventorySlot> slot = std::make_unique<InventorySlot>(posX, posY, slotWidth, slotHeight);

    _components.push_back(std::move(bagImage));
    _interactableComponents.push_back(std::move(slot));
}

void InventoryLayer::handleInput(const SDL_Event &e)
{
    if (e.key.keysym.sym == SDLK_i) {
        _hidden = !_hidden;
    }
}
