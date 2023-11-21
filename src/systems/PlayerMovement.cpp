#include "PlayerMovement.hpp"
#include "components/Player.hpp"
#include "components/Sprite.hpp"
#include "components/Animation.hpp"
#include "components/Movement.hpp"

void movePlayer(entt::registry &reg, uint32_t frametime, SDL_Event &evt)
{
    Vec2i dir = {0, 0};
    Vec2i animPos = {0, 0};

    switch (evt.key.keysym.sym)
    {
        case SDLK_z:
            dir.y = -1;
            break;
        case SDLK_s:
            dir.y = 1;
            break;
        case SDLK_d:
            dir.x = 1;
            break;
        case SDLK_q:
            dir.x = -1;
            animPos.y = 20;
            break;
        default:
            return;
    }

    auto view = reg.view<Player, Sprite, Animation, Movement>();
    
    if (frametime < 1) {
        frametime = 1; // To prevent product by 0 when frametime is lower than 1ms
    }
    for (const entt::entity e : view) {
        view.get<Sprite>(e).pos += static_cast<Vec2i>(dir * frametime * 5);
        Movement &mov = view.get<Movement>(e);
        Animation &anim = view.get<Animation>(e);
        if (mov.direction != dir) {
            anim.spriteSize = {9, 20};
            anim.startPos = animPos;
            anim.curStep = anim.steps; // Will restart the animation from beginning
        }
        mov.direction = dir;
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
            anim.curStep = anim.steps; // Will restart the animation from beginning
            anim.startPos = {0, 40};
            anim.spriteSize = {9, 21};
            mov.direction = {0, 0};
        }
    }
}
