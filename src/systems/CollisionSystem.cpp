#include <iostream>
#include <cmath>

#include "CollisionSystem.hpp"
#include "components/Collider.hpp"
#include "utils/Rect.hpp"

std::vector<Vec2d> getRectVertices(const RectI &rect)
{
    std::vector<Vec2d> vertices;

    vertices.push_back({static_cast<double>(rect.x), static_cast<double>(rect.y)});
    vertices.push_back({static_cast<double>(rect.x), static_cast<double>(rect.y + rect.width)});
    vertices.push_back({static_cast<double>(rect.x + rect.height), static_cast<double>(rect.y)});
    vertices.push_back({static_cast<double>(rect.x + rect.height), static_cast<double>(rect.y + rect.width)});

    return vertices;
}

Vec2d normalize(const Vec2d &v)
{
    double length = std::sqrt(v.x * v.x + v.y * v.y);
    return {v.x / length, v.y / length};
}

std::vector<Vec2d> getAxes(const std::vector<Vec2d> &vertices)
{
    std::vector<Vec2d> axes; // TODO: check for parallel axes
    for (size_t i = 0; i < vertices.size(); i++) {
        const Vec2d p1 = vertices[i];
        const int p2Index = i + 1 == vertices.size() ? 0 : i + 1; // Get the first index if we are at the last one
        const Vec2d p2 = vertices[p2Index];
        const Vec2d edge = p1 - p2;
        const Vec2d normal = normalize({-edge.y, edge.x});
        axes.push_back(normal);
    }
    return axes;
}

int dotProduct(const Vec2d &a, const Vec2d &b)
{
    return a.x * b.x + a.y * b.y;
}

Vec2d getProjection(const Vec2d &axe, const std::vector<Vec2d> &vertices)
{
    double min = dotProduct(axe, vertices[0]);
    double max = min;

    for (size_t i = 0; i < vertices.size(); i++) {
        double p = dotProduct(axe, vertices[i]);
        if (p < min) {
            min = p;
        } else if (p > max) {
            max = p;
        }
    }

    return {min, max};
}

bool areOverlapping(const Vec2d &a, const Vec2d &b)
{
    return a.x <= b.y && a.y >= b.x;
}

bool isColliding(const std::vector<Vec2d> &a, const std::vector<Vec2d> &b)
{
    std::vector<Vec2d> axesA = getAxes(a);
    std::vector<Vec2d> axesB = getAxes(b);

    for (const Vec2d &axe : axesA) {
        Vec2d proj1 = getProjection(axe, a);
        Vec2d proj2 = getProjection(axe, b);

        if (areOverlapping(proj1, proj2) == false) {
            return false;
        }
    }
    for (const Vec2d &axe : axesB) {
        Vec2d proj1 = getProjection(axe, a);
        Vec2d proj2 = getProjection(axe, b);

        if (areOverlapping(proj1, proj2) == false) {
            return false;
        }
    }
    return true;
}

void displayCollider(Collider &collider, SDL::Renderer &renderer)
{
    std::vector<SDL_FPoint> points;
    for (const Vec2d &vertex : collider.vertices) {
        SDL_FPoint point {static_cast<float>(vertex.x), static_cast<float>(vertex.y)};
        points.push_back(point);
    }
    // To make a line between the first and the last vertices
    SDL_FPoint point {static_cast<float>(collider.vertices[collider.vertices.size() - 1].x), static_cast<float>(collider.vertices[0].y)};
    points.push_back(point);

    renderer.setDrawColor(225, 255, 255, 0);
    SDL_RenderDrawLinesF(renderer.getRenderer(), points.data(), collider.vertices.size() + 1);
    renderer.setDrawColor(50, 50, 50, 0);
}

void handleCollisions(entt::registry &reg, SDL::Renderer &renderer)
{
    auto view = reg.view<Collider>();
    for (const entt::entity e : view) {
        Collider &collider = reg.get<Collider>(e);
        if (collider.display == true) {
            displayCollider(collider, renderer);
        }
        for (const entt::entity other : view) {
            if (e == other) {
                continue;
            }
            Collider &otherCollider = reg.get<Collider>(e);
            if (isColliding(collider.vertices, otherCollider.vertices)) {
                std::cout << "Collision" << std::endl;
            }
        }
    }
}
