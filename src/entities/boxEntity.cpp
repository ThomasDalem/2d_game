#include "boxEntity.hpp"
#include "components/Sprite.hpp"
#include "components/Position.hpp"

entt::entity makeBox(entt::registry &reg, TexturesLoader &textureLoader)
{
    entt::entity e = reg.create();

    reg.emplace<Sprite>(
        e,
        false,
        Vec2i{50, 150},
        Vec2f{5.f, 5.f},
        RectI{-1, -1, -1, -1},
        0.0,
        SDL_FLIP_NONE,
        textureLoader.getTexture("../assets/box.png")
    );

    return e;
}
