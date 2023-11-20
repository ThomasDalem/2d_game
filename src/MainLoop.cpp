#include "entt.hpp"
#include "MainLoop.hpp"
#include "SDL/Texture.hpp"
#include "utils/TexturesLoader.hpp"
#include "utils/Timer.hpp"

#include "entities/playerEntity.hpp"

#include "systems/RenderSystem.hpp"
#include "systems/PlayerMovement.hpp"
#include "systems/AnimationSystem.hpp"

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

    Timer frameTimer;
    Timer animTimer;

    animTimer.start();
    while (!_quit) {
        frameTimer.start();
        while (SDL_PollEvent(&e) != 0) {
            if (e.type == SDL_QUIT) {
                _quit = true;
            }
            if (e.type == SDL_KEYDOWN) {
                movePlayer(reg, frameTimer.getDeltaTime(), e);
            }
        }
        _app.getRenderer().clear();

        animateSprites(reg, animTimer.getDeltaTime());
        updateRenderSystem(_app.getRenderer(), reg);

        _app.getRenderer().present();

    }
}
