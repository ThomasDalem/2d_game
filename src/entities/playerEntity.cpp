#include "playerEntity.hpp"
#include "components/Sprite.hpp"
#include "components/Player.hpp"
#include "components/Animation.hpp"
#include "components/Movement.hpp"
#include "components/Relationship.hpp"
#include "components/Collider.hpp"

entt::entity makePlayerBody(entt::registry &reg, TexturesLoader &texturesLoader)
{
    const entt::entity e = reg.create();

    const int x = 300;
    const int y = 300;
    const int spriteSizeX = 90;
    const int spriteSizeY = 95;

    reg.emplace<Player>(e);
    reg.emplace<Sprite>(
        e,
        false, // Hidden
        Vec2i{x, y}, // Pos on screen
        Vec2f{5.f, 5.f}, // Scale
        RectI{0, 16, 18, 19}, // Spritesheet rect -1 for whole sprite
        RectI{x, y, spriteSizeX, spriteSizeY}, // Displayed sprite rect
        0.0, // Angle of sprite
        SDL_FLIP_HORIZONTAL, // Flip
        texturesLoader.getTexture("assets/player_anim3.png")
    );
    reg.emplace<Animation>(
        e,
        0U, // startTime
        600U, // Duration
        static_cast<uint16_t>(0), // CurStep
        static_cast<uint16_t>(6), // Steps
        Vec2i{0, 16}, // StartPos
        Vec2i{18, 19}, // SpriteSize (for each step)
        false // Play anim ?
    );
    reg.emplace<Movement>(e, Vec2i{0, 0}, 2.f, false);
    std::vector<Vec2d> colliderVertices {
        {x, y},
        {x + spriteSizeX, y},
        {x + spriteSizeX, y + spriteSizeY},
        {x, y + spriteSizeY}
    };
    reg.emplace<Collider>(e, colliderVertices, true);

    return e;
}

entt::entity makePlayerLegs(entt::registry &reg, TexturesLoader &texturesLoader, entt::entity playerBody)
{
    const entt::entity e = reg.create();

    reg.emplace<Player>(e);
    reg.emplace<Sprite>(
        e,
        true, // Hidden
        Vec2i{300, 300}, // Pos on screen
        Vec2f{5.f, 5.f}, // Scale
        RectI{0, 0, 18, 15}, // Spritesheet rect -1 for whole sprite
        RectI{300, 300, 90, 95}, // Displayed sprite rect
        0.0, // Angle of sprite
        SDL_FLIP_HORIZONTAL, // Flip
        texturesLoader.getTexture("assets/player_anim3.png"));
    reg.emplace<Animation>(
        e,
        0U, // startTime
        600U, // Duration
        static_cast<uint16_t>(0), // CurStep
        static_cast<uint16_t>(6), // Steps
        Vec2i{0, 0}, // StartPos
        Vec2i{18, 15}, // SpriteSize (for each step)
        false // Play anim ?);
    );
    reg.emplace<Movement>(e, Vec2i{0, 0}, 2.f, false);
    reg.emplace<Relationship>(e, playerBody);

    return e;
}
