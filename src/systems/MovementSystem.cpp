#include "MovementSystem.hpp"
#include "components/Movement.hpp"
#include "components/Sprite.hpp"
#include "components/Collider.hpp"

void moveSprites(entt::registry &reg, uint32_t deltaTime)
{
    auto view = reg.view<Movement, Sprite>();

    if (deltaTime < 1) {
        deltaTime = 1; // To prevent product by 0 when frametime is lower than 1ms
    }
    for (const entt::entity e : view) {
        Movement &mov = reg.get<Movement>(e);
        Sprite &sprite = reg.get<Sprite>(e);

        const Vec2i posDelta = mov.direction * mov.speed * deltaTime;
        sprite.pos += posDelta;
        sprite.rect.x = sprite.pos.x;
        sprite.rect.y = sprite.pos.y;

        Collider *collider = reg.try_get<Collider>(e);

        if (collider != nullptr) {
            for (Vec2d &vertex : collider->vertices) {
                vertex += posDelta;
            }
        }
    }
}
