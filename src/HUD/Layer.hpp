#ifndef LAYER_HPP
#define LAYER_HPP

#include <vector>
#include <memory>
#include "Component.hpp"
#include "SDL/Renderer.hpp"

namespace HUD
{
    class Layer
    {
    public:
        Layer(bool hidden = false);

        void setHidden(bool hidden);
        bool getHidden();

        void draw(SDL::Renderer &renderer);

    protected:
        std::vector<std::unique_ptr<Component>> _components;
        bool _hidden;
    };
}

#endif // LAYER_HPP