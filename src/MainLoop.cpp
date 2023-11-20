#include "entt.hpp"
#include "MainLoop.hpp"
#include "SDL/Texture.hpp"
#include "utils/TexturesLoader.hpp"
#include "utils/FrameTimer.hpp"

#include "entities/playerEntity.hpp"

#include "systems/RenderSystem.hpp"
#include "systems/PlayerMovement.hpp"

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

    FrameTimer frameTimer;

    while (!_quit) {
        frameTimer.start();
        while (SDL_PollEvent(&e) != 0) {
            if (e.type == SDL_QUIT) {
                _quit = true;
            }
            if (e.type == SDL_KEYDOWN) {
                movePlayer(reg, frameTimer.getFrametime(), e);
            }
        }
        _app.getRenderer().clear();

        updateRenderSystem(_app.getRenderer(), reg);

        _app.getRenderer().present();

    }
}
