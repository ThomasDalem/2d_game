#include "entt.hpp"
#include "MainLoop.hpp"
#include "SDL/Texture.hpp"
#include "utils/TexturesLoader.hpp"

#include "entities/playerEntity.hpp"

#include "systems/RenderSystem.hpp"

MainLoop::MainLoop(SDL::App &app): _app(app), _quit(false)
{

}

MainLoop::~MainLoop()
{

}

void MainLoop::loop()
{
    entt::registry reg;
    TexturesLoader texturesLoader(_app.getRenderer());
    SDL_Event e;

    makePlayer(reg, texturesLoader);

    SDL::Texture &texture = texturesLoader.getTexture("../assets/tree.png");
    while (!_quit) {
        while (SDL_PollEvent(&e) != 0) {
            if (e.type == SDL_QUIT) {
                _quit = true;
            }
        }
        SDL_Rect rect = {0, 0, 200, 200};
        _app.getRenderer().clear();

        updateRenderSystem(_app.getRenderer(), reg);

        _app.getRenderer().copy(texture, NULL, &rect);
        _app.getRenderer().present();
    }
}
