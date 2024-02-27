#ifndef BOX_ENTITY_HPP
#define BOX_ENTITY_HPP

#include "entt.hpp"
#include "utils/TexturesLoader.hpp"

entt::entity makeBox(entt::registry &reg, TexturesLoader &textureLoader);

#endif // BOX_ENTITY_HPP