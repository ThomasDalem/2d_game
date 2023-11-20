#include <iostream>
#include "PlayerMovement.hpp"
#include "components/Player.hpp"
#include "components/Sprite.hpp"

void movePlayer(entt::registry &reg, uint32_t frametime, SDL_Event &evt)
{
    auto view = reg.view<Player, Sprite>();
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
            break;
    }
    
    std::cout << "Frametime: " << frametime << std::endl;
    if (frametime < 1) {
        frametime = 1; // To prevent product by 0 when frametime is lower than 1ms
    }
    for (const entt::entity e : view) {
        view.get<Sprite>(e).pos += static_cast<Vec2i>(dir * frametime * 5);
    }
}
