#include "entt.hpp"
#include "MainLoop.hpp"
#include "SDL/Texture.hpp"
#include "utils/TexturesLoader.hpp"
#include "utils/Timer.hpp"

#include "entities/playerEntity.hpp"
#include "entities/boxEntity.hpp"
#include "entities/inventoryEntity.hpp"
#include "entities/itemSlot.hpp"

#include "systems/RenderSystem.hpp"
#include "systems/PlayerMovement.hpp"
#include "systems/AnimationSystem.hpp"
#include "systems/MovementSystem.hpp"
#include "systems/CollisionSystem.hpp"
#include "systems/InventorySystem.hpp"

#include "components/Sprite.hpp"

#include "HUD/layers/InventoryLayer.hpp"

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

    const entt::entity playerBody = makePlayerBody(reg, texturesLoader);
    makePlayerLegs(reg, texturesLoader, playerBody);
    makeBox(reg, texturesLoader);
    std::unique_ptr<HUD::Layer> inventoryLayer = std::make_unique<HUD::InventoryLayer>(texturesLoader, _app.getScreenWidth(), _app.getScreenHeight());
    inventoryLayer->setHidden(false);

    Timer frameTimer;
    Timer animTimer;

    animTimer.start();
    while (!_quit) {
        frameTimer.start();
        while (SDL_PollEvent(&e) != 0) {
            if (e.type == SDL_QUIT) {
                _quit = true;
            }
            inventoryLayer->handleInput(e);
            if (e.type == SDL_KEYDOWN) {
                movePlayer(reg, e);
            }
            else if (e.type == SDL_KEYUP) {
                stopPlayer(reg, e);
            } 
        }
        _app.getRenderer().setDrawColor(50, 50, 50, 0);
        _app.getRenderer().clear();

        turnPlayer(reg);
        moveSprites(reg, frameTimer.getDeltaTime());
        animateSprites(reg, animTimer.getDeltaTime());
        handleCollisions(reg);
        updateRenderSystem(reg, _app.getRenderer(), true);

        inventoryLayer->draw(_app.getRenderer());

        _app.getRenderer().present();
    }
}
