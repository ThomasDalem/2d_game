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

        bool isDragged() const;

        virtual void onClickDown(int x, int y);
        virtual void onClick(int x, int y);
        void onClickUp(int x, int y);
    
    protected:
        bool _isDragged;
    };
}

#endif // DRAGGABLE_HPP