#ifndef INVENTORY_LAYER_HPP
#define INVENTORY_LAYER_HPP

#include "HUD/Layer.hpp"
#include "utils/TexturesLoader.hpp"

namespace HUD
{
    class InventoryLayer: public Layer
    {
    public:
        InventoryLayer(TexturesLoader &textureLoader, int screenWidth, int screenHeight);

    private:
        bool hidden;
    };
}

#endif // INVENTORY_LAYER_HPP