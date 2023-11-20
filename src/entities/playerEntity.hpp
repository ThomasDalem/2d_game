#ifndef PLAYER_ENTITY_HPP
#define PLAYER_ENTITY_HPP

#include "entt.hpp"
#include "utils/TexturesLoader.hpp"

entt::entity makePlayer(entt::registry &reg, TexturesLoader &texturesLoader);

#endif // PLAYER_ENTITY_HPP