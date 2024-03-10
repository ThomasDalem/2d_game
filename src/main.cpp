#include <iostream>
#include "SDL/App.hpp"
#include "SDL/Surface.hpp"
#include "MainLoop.hpp"

int main()
{
    SDL::App app(1800, 1300);
    MainLoop mainLoop(app);

    mainLoop.loop();

    return (0);
}
