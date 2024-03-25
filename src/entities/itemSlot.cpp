#include "itemSlot.hpp"

#include "components/tags/GUI.hpp"
#include "components/tags/Button.hpp"
#include "components/Rectangle.hpp"

entt::entity makeItemSlot(entt::registry &reg, const Vec2i &invPos, const Vec2i &gridPos)
{
    const entt::entity e = reg.create();
    const int invTopPadding = 100;
    const int invLeftPadding = 340;

    reg.emplace<GUI>(e);
    reg.emplace<Rectangle>(
        e,
        invPos.x + invTopPadding + (gridPos.x * 100),
        invPos.y + invLeftPadding + (gridPos.y * 50),
        80,
        80
    );
    reg.emplace<Button>(e);

    return e;
}
