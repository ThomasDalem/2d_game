#include "entt.hpp"
#include "MainLoop.hpp"
#include "SDL/Texture.hpp"
#include "utils/TexturesLoader.hpp"
#include "utils/Timer.hpp"

#include "entities/playerEntity.hpp"
#include "entities/boxEntity.hpp"

#include "systems/RenderSystem.hpp"
#include "systems/PlayerMovement.hpp"
#include "systems/AnimationSystem.hpp"
#include "systems/MovementSystem.hpp"

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

    entt::entity playerBody = makePlayerBody(reg, texturesLoader);
    makePlayerLegs(reg, texturesLoader, playerBody);
    makeBox(reg, texturesLoader);

    Timer frameTimer;
    Timer animTimer;

    animTimer.start();
    while (!_quit) {
        frameTimer.start();
        while (SDL_PollEvent(&e) != 0) {
            if (e.type == SDL_QUIT) {
                _quit = true;
            }
            else if (e.type == SDL_KEYDOWN) {
                movePlayer(reg, e);
            }
            else if (e.type == SDL_KEYUP) {
                stopPlayer(reg, e);
            } 
        }
        _app.getRenderer().clear();

        turnPlayer(reg);
        moveSprites(reg, frameTimer.getDeltaTime());
        animateSprites(reg, animTimer.getDeltaTime());
        updateRenderSystem(_app.getRenderer(), reg);

        _app.getRenderer().present();

    }
}
