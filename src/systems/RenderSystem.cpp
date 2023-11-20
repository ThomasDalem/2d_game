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
        renderer.copy(sprite.texture, NULL, &rect);
    });
}
