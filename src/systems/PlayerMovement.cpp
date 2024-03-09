#include "PlayerMovement.hpp"
#include "components/Player.hpp"
#include "components/Sprite.hpp"
#include "components/Animation.hpp"
#include "components/Movement.hpp"
#include "components/Relationship.hpp"

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
        const Parent *rel = reg.try_get<Parent>(e);

        if (rel && rel->parent != entt::null) {
            sprite.hidden = false;
            mov.move = true;
            anim.playAnim = true;
            continue; // will be moved as child of player
        }

        if (dir.x != mov.direction.x) {
            mov.direction.x += dir.x;
        }
        if (dir.y != mov.direction.y) {
            mov.direction.y += dir.y;
        }
        if (mov.direction.x != 0 || mov.direction.y != 0) {
            mov.move = true;
            anim.playAnim = true;
        }
    }
}

void stopPlayer(entt::registry &reg, SDL_Event &evt)
{
    auto view = reg.view<Player, Sprite, Animation, Movement>();

    for (const entt::entity e : view) {
        Movement &mov = view.get<Movement>(e);
        Animation &anim = view.get<Animation>(e);
        Sprite &sprite = view.get<Sprite>(e);
        Parent *rel = reg.try_get<Parent>(e);

        if (evt.key.keysym.sym == SDLK_z && mov.direction.y != 1) {
            mov.direction.y = 0;
        }
        if (evt.key.keysym.sym == SDLK_s && mov.direction.y != -1) {
            mov.direction.y = 0;
        }
        if (evt.key.keysym.sym == SDLK_d && mov.direction.x != -1) {
            mov.direction.x = 0;
        }
        if (evt.key.keysym.sym == SDLK_q && mov.direction.x != 1) {
            mov.direction.x = 0;
        }

        if (mov.direction.x != 0 || mov.direction.y != 0) {
            continue;
        }

        sprite.textureRect.x = 0;
        anim.curStep = anim.steps; // Restart the animation from the beginning
        anim.playAnim = false;

        if (rel && rel->parent != entt::null) { // if it's the legs
            sprite.hidden = true;
            continue; // will be moved as child of player
        }

        mov.move = false;
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
