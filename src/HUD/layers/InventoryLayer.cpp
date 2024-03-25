#include "InventoryLayer.hpp"
#include "HUD/Image.hpp"
#include <iostream>

using namespace HUD;

InventoryLayer::InventoryLayer(TexturesLoader &textureLoader, int screenWidth, int screenHeight): Layer()
{
    {
        std::unique_ptr<Image> bagImage = std::make_unique<Image>("assets/bag.png", textureLoader);
        const int centerX = (screenWidth / 2) - (bagImage->getWidth() / 2);
        const int centerY = (screenHeight / 2) - (bagImage->getHeight() / 2);
        std::cout << bagImage->getWidth() << " : " << bagImage->getHeight() << "\n";
        bagImage->setPos({centerX, centerY});
        _components.push_back(std::move(bagImage));
    }
}
