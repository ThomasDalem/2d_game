#include "AnimationSystem.hpp"
#include "components/Animation.hpp"
#include "components/Sprite.hpp"
#include <iostream>

void animateSprites(entt::registry &reg, uint32_t time)
{
    auto view = reg.view<Animation, Sprite>();

    view.each([time](Animation &anim, Sprite &sprite){
        if (anim.playAnim == false || anim.steps == 0) {
            return;
        }
        if (anim.curStep >= anim.steps - 1) {
            anim.curStep = 0;
            anim.startTime = time;
        }

        const uint32_t timePerFrame = anim.duration / static_cast<uint32_t>(anim.steps);
        const int currentStep = std::floor((time - anim.startTime) / timePerFrame);
        sprite.rect.x = anim.startPos.x + anim.spriteSize.x * currentStep;
        sprite.rect.y = anim.startPos.y;
        sprite.rect.height = anim.spriteSize.y;
        sprite.rect.width = anim.spriteSize.x;
        std::cout << sprite.rect << "\n";
        anim.curStep = currentStep;
    });
}
