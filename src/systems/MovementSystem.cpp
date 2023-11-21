#include "MovementSystem.hpp"
#include "components/Movement.hpp"
#include "components/Sprite.hpp"

void moveSprites(entt::registry &reg, uint32_t deltaTime)
{
    auto view = reg.view<Movement, Sprite>();

    if (deltaTime < 1) {
        deltaTime = 1; // To prevent product by 0 when frametime is lower than 1ms
    }
    view.each([deltaTime](Movement &mov, Sprite &sprite) {
        if (mov.move) {
            sprite.pos += mov.direction * mov.speed * deltaTime;
        }
    });
}
