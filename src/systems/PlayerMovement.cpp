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
        Parent *rel = reg.try_get<Parent>(e);

        if (mov.direction != dir) {
            anim.curStep = anim.steps; // Restart the animation from the beginning
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
            Parent *rel = reg.try_get<Parent>(e);

            if (rel && rel->parent != entt::null) { // if it's the legs
                sprite.hidden = true;
            }
            if (mov.direction != KEYS_DIRECTIONS.at(static_cast<SDL_KeyCode>(evt.key.keysym.sym))) {
                continue;
            }

            sprite.textureRect.x = 0;
            anim.curStep = anim.steps; // Restart the animation from the beginning
            mov.direction = {0, 0};
            anim.playAnim = false;
            mov.move = false;
        }
    }
}

void turnPlayer(entt::registry &reg)
{
    auto view = reg.view<Player, Sprite>();

    for (const entt::entity e : view) {
        Sprite &sprite = view.get<Sprite>(e);

        int mouseX = 0;
        int mouseY = 0;
        SDL_GetMouseState(&mouseX, &mouseY);
        const int centerX = sprite.pos.x + sprite.rect.width / 2;
        const int centerY = sprite.pos.y + sprite.rect.height / 2;

        sprite.angle = atan2(centerY - mouseY, centerX - mouseX) * 180.0 / M_PI;
    }
}
