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

        void draw(SDL::Renderer &renderer);

    private:
        std::unique_ptr<Component> child;
    };
}

#endif // DRAGGABLE_HPP