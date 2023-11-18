#include "MainLoop.hpp"
#include "SDL/Surface.hpp"
#include "SDL/Texture.hpp"

MainLoop::MainLoop(SDL::App &app): _app(app), _quit(false)
{

}

MainLoop::~MainLoop()
{

}

void MainLoop::loop()
{
    SDL::Texture texture("../assets/tree.png", _app.getRenderer());
    SDL_Event e;

    while (!_quit) {
        while (SDL_PollEvent(&e) != 0) {
            if (e.type == SDL_QUIT) {
                _quit = true;
            }
        }
        SDL_Rect rect = {0, 0, 200, 200};
        _app.getRenderer().clear();
        _app.getRenderer().copy(texture, NULL, &rect);
        _app.getRenderer().present();
    }
}
