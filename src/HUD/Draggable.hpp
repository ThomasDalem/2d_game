#ifndef DRAGGABLE_HPP
#define DRAGGABLE_HPP

#include <memory>
#include "HUD/Interactable.hpp"

namespace HUD
{
    class Draggable : public Interactable
    {
    public:
        Draggable(int x, int y, int width, int height);

        ComponentType getType() const;

        void onClickDown(int x, int y);
    };
}

#endif // DRAGGABLE_HPP