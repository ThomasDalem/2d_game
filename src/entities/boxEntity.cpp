#include "boxEntity.hpp"
#include "components/Sprite.hpp"
#include "components/Position.hpp"
#include "components/Collider.hpp"

entt::entity makeBox(entt::registry &reg, TexturesLoader &textureLoader)
{
    entt::entity e = reg.create();

    const int x = 50;
    const int y = 150;
    const int spriteSizeX = 90;
    const int spriteSizeY = 90;

    reg.emplace<Sprite>(
        e,
        false,
        Vec2i{x, y},
        Vec2f{5.f, 5.f},
        RectI{-1, -1, -1, -1},
        RectI{x, y, 18, 18},
        0.0,
        SDL_FLIP_NONE,
        textureLoader.getTexture("assets/box.png")
    );
    std::vector<Vec2d> colliderVertices {
        {x, y},
        {x + spriteSizeX, y},
        {x + spriteSizeX, y + spriteSizeY},
        {x, y + spriteSizeY}
    };
    reg.emplace<Collider>(e, colliderVertices, true);

    return e;
}
