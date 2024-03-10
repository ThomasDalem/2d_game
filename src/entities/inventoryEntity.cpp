#include "inventoryEntity.hpp"
#include "components/Sprite.hpp"
#include "components/Inventory.hpp"
#include "components/GUI.hpp"

entt::entity makeInventory(entt::registry &reg, TexturesLoader &textureLoader, uint16_t screenX, uint16_t screenY)
{
    entt::entity e = reg.create();

    SDL::Texture &texture = textureLoader.getTexture("assets/bag.png");

    const int x = screenX / 2 - texture.getWidth() / 2;
    const int y = screenY / 2 - texture.getHeight() / 2;

    reg.emplace<Sprite>(
        e,
        true,
        Vec2i{x, y},
        Vec2f{1.f, 1.f},
        RectI{-1, -1, -1, -1},
        RectI{x, y, 33, 49},
        0.0,
        SDL_FLIP_NONE,
        texture
    );
    reg.emplace<Inventory>(e);
    reg.emplace<GUI>(e);

    return e;
}
