#include "InventorySystem.hpp"
#include "components/Inventory.hpp"
#include <iostream>

void openInventory(entt::registry &reg, SDL_Event &evt)
{
    auto view = reg.view<Inventory, Sprite>();

    if (evt.key.keysym.sym != SDLK_i) {
        return;
    }

    view.each([evt](Inventory &inv, Sprite &sprite){
        inv.isOpen = !inv.isOpen;
        sprite.hidden = !inv.isOpen;
    });
}
