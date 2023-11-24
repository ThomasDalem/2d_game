#include "PlayerMovement.hpp"
#include "components/Player.hpp"
#include "components/Sprite.hpp"
#include "components/Animation.hpp"
#include "components/Movement.hpp"
#include "components/Relationship.hpp"

#include <iostream>

void movePlayer(entt::registry &reg, SDL_Event &evt)
{
    Vec2i dir = {0, 0};

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
            break;
        default:
            return;
    }

    auto view = reg.view<Player, Animation, Movement, Sprite>();

    for (const entt::entity e : view) {
        Movement &mov = view.get<Movement>(e);
        Animation &anim = view.get<Animation>(e);
        Sprite &sprite = view.get<Sprite>(e);
        Relationship *rel = reg.try_get<Relationship>(e);

        if (mov.direction != dir) {
            anim.curStep = anim.steps; // Will restart the animation from beginning
        }
        if (rel && rel->parent != entt::null) {
            sprite.hidden = false;
        }

        anim.playAnim = true;
        mov.direction = dir;
        mov.move = true;
    }
}

void stopPlayer(entt::registry &reg, SDL_Event &evt)
{
    if (evt.key.keysym.sym == SDLK_z ||
        evt.key.keysym.sym == SDLK_s ||
        evt.key.keysym.sym == SDLK_q ||
        evt.key.keysym.sym == SDLK_d) 
    {
        auto view = reg.view<Player, Sprite, Animation, Movement>();
        for (const entt::entity e : view) {
            Movement &mov = view.get<Movement>(e);
            Animation &anim = view.get<Animation>(e);
            Sprite &sprite = view.get<Sprite>(e);
            Relationship *rel = reg.try_get<Relationship>(e);

            if (rel && rel->parent != entt::null) { // if its the legs
                sprite.hidden = true;
            }
            if (mov.direction != KEYS_DIRECTIONS.at(static_cast<SDL_KeyCode>(evt.key.keysym.sym))) {
                continue;
            }

            sprite.rect.x = 0;
            anim.curStep = anim.steps; // Will restart the animation from beginningvv  
            mov.direction = {0, 0};
            anim.playAnim = false;
            mov.move = false;
        }
    }
}

void turnPlayer(entt::registry &reg)
{
    auto view = reg.view<Player, Sprite>();

    view.each([](Sprite &sprite){
        int mouseX = 0;
        int mouseY = 0;
        SDL_GetMouseState(&mouseX, &mouseY);
        sprite.angle = atan2(sprite.pos.y - mouseY, sprite.pos.x - mouseX) * 180 / M_PI;
    });
}
