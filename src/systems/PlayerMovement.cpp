#include "PlayerMovement.hpp"
#include "components/Player.hpp"
#include "components/Sprite.hpp"
#include "components/Animation.hpp"
#include "components/Movement.hpp"

void movePlayer(entt::registry &reg, SDL_Event &evt)
{
    Vec2i dir = {0, 0};
    Vec2i animPos = {0, 0};

    switch (evt.key.keysym.sym)
    {
        case SDLK_z:
            dir.y = -1;
            animPos.y = 27;
            break;
        case SDLK_s:
            dir.y = 1;
            animPos.y = 9;
            break;
        case SDLK_d:
            dir.x = 1;
            animPos.y = 0;
            break;
        case SDLK_q:
            dir.x = -1;
            animPos.y = 18;
            break;
        default:
            return;
    }

    auto view = reg.view<Player, Animation, Movement>();

    for (const entt::entity e : view) {
        Movement &mov = view.get<Movement>(e);
        Animation &anim = view.get<Animation>(e);
        if (mov.direction != dir) {
            anim.startPos = animPos;
            anim.curStep = anim.steps; // Will restart the animation from beginning
        }
        anim.playAnim = true;
        mov.direction = dir;
        mov.move = true;
    }
}

void stopPlayer(entt::registry &reg, SDL_Event &evt)
{
    if (
        evt.key.keysym.sym == SDLK_z ||
        evt.key.keysym.sym == SDLK_s ||
        evt.key.keysym.sym == SDLK_q ||
        evt.key.keysym.sym == SDLK_d) 
    {
        auto view = reg.view<Player, Sprite, Animation, Movement>();
        for (const entt::entity e : view) {
            Movement &mov = view.get<Movement>(e);
            Animation &anim = view.get<Animation>(e);
            Sprite &sprite = view.get<Sprite>(e);
            if (mov.direction != KEYS_DIRECTIONS.at(static_cast<SDL_KeyCode>(evt.key.keysym.sym))) {
                continue;
            }
            sprite.rect.x = 0;
            anim.curStep = anim.steps; // Will restart the animation from beginning
            anim.spriteSize = {9, 9};
            mov.direction = {0, 0};
            mov.move = false;
        }
    }
}
