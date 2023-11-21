#include "playerEntity.hpp"
#include "components/Sprite.hpp"
#include "components/Player.hpp"
#include "components/Animation.hpp"
#include "components/Movement.hpp"

entt::entity makePlayer(entt::registry &reg, TexturesLoader &texturesLoader)
{
    const entt::entity e = reg.create();

    reg.emplace<Sprite>(
        e,
        Vec2i{0, 0}, // Pos on screen
        Vec2f{5.f, 5.f}, // Scale
        RectI{0, 0, 9, 20}, // Spritesheet rect -1 for whole sprite
        texturesLoader.getTexture("../assets/player_anim.png")
    );
    reg.emplace<Player>(e);
    reg.emplace<Animation>(
        e,
        0U, // startTime
        1000U, // Duration
        static_cast<uint16_t>(0), // CurStep
        static_cast<uint16_t>(4), // Steps
        Vec2i{0, 40}, // StartPos
        Vec2i{9, 21}, // SpriteSize (for each step)
        true // Play anim ?
    );
    reg.emplace<Movement>(e, Vec2i{0, 0}, 2.f, false);

    return e;
}
