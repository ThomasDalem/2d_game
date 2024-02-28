#include "RenderSystem.hpp"
#include "components/Sprite.hpp"

void updateRenderSystem(SDL::Renderer &renderer, entt::registry &reg)
{
    const auto view = reg.view<Sprite>();

    view.each([&renderer](const Sprite &sprite){
        if (sprite.hidden) {
            return;
        }
        const int width = sprite.rect.width == -1 ? sprite.texture.getWidth() : sprite.rect.width; // TODO: create value in sprite for texture size
        const int height = sprite.rect.height == -1 ? sprite.texture.getHeight() : sprite.rect.height; // TODO: create value in sprite for texture size
        SDL_Rect rect = {
            sprite.pos.x,
            sprite.pos.y,
            static_cast<int>(width * sprite.scale.x),
            static_cast<int>(height * sprite.scale.y)
        };
        if (sprite.rect.width < 0 || sprite.rect.height < 0) {
            renderer.copyEx(sprite.texture, sprite.angle, NULL, &rect, sprite.flip);
        } else {
            SDL_Rect spriteRect = {
                sprite.rect.x,
                sprite.rect.y,
                sprite.rect.width,
                sprite.rect.height
            };
            rect.w = sprite.rect.width * sprite.scale.x;
            rect.h = sprite.rect.height * sprite.scale.y;

            renderer.copyEx(sprite.texture, sprite.angle, &spriteRect, &rect, sprite.flip);
        }
    });
}
