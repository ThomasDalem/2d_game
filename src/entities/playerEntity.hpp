#ifndef PLAYER_ENTITY_HPP
#define PLAYER_ENTITY_HPP

#include "entt.hpp"
#include "utils/TexturesLoader.hpp"

entt::entity makePlayerBody(entt::registry &reg, TexturesLoader &texturesLoader);
entt::entity makePlayerLegs(entt::registry &reg, TexturesLoader &texturesLoader, entt::entity playerBody);

#endif // PLAYER_ENTITY_HPP