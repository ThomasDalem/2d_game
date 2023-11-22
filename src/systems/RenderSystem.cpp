#include "RenderSystem.hpp"
#include "components/Sprite.hpp"

void updateRenderSystem(SDL::Renderer &renderer, entt::registry &reg)
{
    const auto view = reg.view<Sprite>();

    view.each([&renderer](const Sprite &sprite){
        SDL_Rect rect = {
            sprite.pos.x,
            sprite.pos.y,
            static_cast<int>(sprite.texture.getWidth() * sprite.scale.x),
            static_cast<int>(sprite.texture.getHeight() * sprite.scale.y)
        };
        Vec2i center = sprite.texture.getCenter();
        if (sprite.rect.width < 0 || sprite.rect.height < 0) {
            renderer.copyEx(sprite.texture, center, sprite.angle, NULL, &rect);
        } else {
            SDL_Rect spriteRect = {
                sprite.rect.x,
                sprite.rect.y,
                sprite.rect.width,
                sprite.rect.height
            };
            rect.w = sprite.rect.width * sprite.scale.x;
            rect.h = sprite.rect.height * sprite.scale.y;
            renderer.copyEx(sprite.texture, center, sprite.angle, &spriteRect, &rect);
        }
    });
}
