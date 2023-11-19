#ifndef RENDERSYSTEM_HPP
#define RENDERSYSTEM_HPP

#include "entt.hpp"
#include "SDL/Renderer.hpp"

void updateRenderSystem(SDL::Renderer &renderer, entt::registry &reg);

#endif // RENDERSYSTEM_HPP