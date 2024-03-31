#ifndef INTERACTABLE_HPP
#define INTERACTABLE_HPP

#include "HUD/Component.hpp"

namespace HUD
{
    enum ComponentType
    {
        BUTTON,
        DRAGGABLE
    };

    class Interactable : public Component
    {
    public:
        Interactable(int x, int y, int width, int height);

        virtual ComponentType getType() const = 0;

        virtual void onClickDown([[maybe_unused]]int x, [[maybe_unused]]int y) {};
        virtual void onClickUp([[maybe_unused]]int x, [[maybe_unused]]int y) {};
        virtual void onHoverEnter() {};
        virtual void onHover([[maybe_unused]]int x, [[maybe_unused]]int y) {};
        virtual void onHoverQuit() {};
    
    private:
        bool _isHovered;
        bool _isClicked;
    };
}

#endif // INTERACTABLE_HPP
