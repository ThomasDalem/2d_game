#include "playerEntity.hpp"
#include "components/Sprite.hpp"
#include "components/Player.hpp"

entt::entity makePlayer(entt::registry &reg, TexturesLoader &texturesLoader)
{
    const entt::entity e = reg.create();

    reg.emplace<Sprite>(e, Vec2i{0, 0}, Vec2f{0.2f, 0.2f}, texturesLoader.getTexture("../assets/tree.png"));
    reg.emplace<Player>(e);

    return e;
}
