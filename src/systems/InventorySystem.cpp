#include "InventorySystem.hpp"
#include "components/Inventory.hpp"
#include "components/Button.hpp"
#include "components/Rectangle.hpp"

void handleInputsInventory(entt::registry &reg, SDL_Event &evt)
{
    auto invView = reg.view<Inventory, Sprite>();

    for (const entt::entity &e : invView) {
        Inventory &inv = reg.get<Inventory>(e);
        Sprite &sprite = reg.get<Sprite>(e);

        if (evt.key.keysym.sym == SDLK_i) {
            inv.isOpen = !inv.isOpen;
            sprite.hidden = !inv.isOpen;
        }
    }

    int x = 0;
    int y = 0;
    SDL_GetMouseState(&x, &y);
    auto slotsView = reg.view<Button>();

    for (const entt::entity &e : slotsView) {
        Rectangle *rect = reg.try_get<Rectangle>(e);
        if (rect == nullptr) {
            continue;
        }
        if (pointInRect(rect->rect, x, y)) {
            rect->color = {150, 150, 150, 0};
        }
        else {
            rect->color = {255, 255, 255, 50};
        }
    }
}
