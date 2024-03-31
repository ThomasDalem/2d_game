#include "HUD/Interactable.hpp"

using namespace HUD;

Interactable::Interactable(int x, int y, int width, int height)
    : Component(x, y, width, height)
    , _isHovered(false)
    , _isClicked(false)
{}