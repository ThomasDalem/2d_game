#include <iostream>

#include "AnimationSystem.hpp"
#include "components/Animation.hpp"
#include "components/Sprite.hpp"

void animateSprites(entt::registry &reg, uint32_t time)
{
    auto view = reg.view<Animation, Sprite>();

    view.each([time](Animation &anim, Sprite &sprite){
        if (anim.playAnim == false || anim.steps == 0) {
            return;
        }
        if (anim.curStep >= anim.steps) {
            anim.curStep = 0;
            anim.startTime = time;
        }

        uint32_t timePerFrame = anim.duration / static_cast<uint32_t>(anim.steps);
        int currentStep = std::floor((time - anim.startTime) / timePerFrame);
        sprite.rect.x = anim.startPos.x + anim.spriteSize.x * currentStep;
        anim.curStep = currentStep;
    });
}
