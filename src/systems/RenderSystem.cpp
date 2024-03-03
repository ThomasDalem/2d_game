#include "RenderSystem.hpp"
#include "components/Sprite.hpp"

void updateRenderSystem(SDL::Renderer &renderer, entt::registry &reg)
{
    const auto view = reg.view<Sprite>();

    view.each([&renderer](Sprite &sprite){
        if (sprite.hidden) {
            return;
        }

        if (sprite.textureRect.height == -1) {
            sprite.rect.width = sprite.texture.getWidth() * sprite.scale.x;
            sprite.rect.height = sprite.texture.getHeight() * sprite.scale.y;
        } else {
            sprite.rect.width = sprite.textureRect.width * sprite.scale.x;
            sprite.rect.height = sprite.textureRect.height * sprite.scale.y;
        }

        SDL_Rect rect = {
            sprite.pos.x,
            sprite.pos.y,
            sprite.rect.width,
            sprite.rect.height
        };

        if (sprite.textureRect.width < 0 || sprite.textureRect.height < 0) {
            renderer.copyEx(sprite.texture, sprite.angle, NULL, &rect, sprite.flip);
        } else {
            SDL_Rect spriteRect = {
                sprite.textureRect.x,
                sprite.textureRect.y,
                sprite.textureRect.width,
                sprite.textureRect.height
            };
            renderer.copyEx(sprite.texture, sprite.angle, &spriteRect, &rect, sprite.flip);
        }
    });
}
