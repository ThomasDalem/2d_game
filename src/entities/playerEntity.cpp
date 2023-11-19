#include "playerEntity.hpp"
#include "components/Sprite.hpp"

entt::entity makePlayer(entt::registry &reg, TexturesLoader &texturesLoader)
{
    const entt::entity e = reg.create();
    reg.emplace<Sprite>(e, Vec2f{0, 0}, Vec2f{1, 1}, texturesLoader.getTexture("../assets/tree.png"));
    return e;
}
