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

        void handleInput(const SDL_Event &e, int mouseX, int mouseY);
        void checkMousePos(int x, int y);

    private:
        void clickedComponents(int x, int y);
    };
}

#endif // INVENTORY_LAYER_HPP