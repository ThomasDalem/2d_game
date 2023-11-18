#include <iostream>
#include "SDL/App.hpp"
#include "SDL/Surface.hpp"
#include "MainLoop.hpp"

int main()
{
    SDL::App app(1200, 800);
    MainLoop mainLoop(app);

    mainLoop.loop();

    return (0);
}
