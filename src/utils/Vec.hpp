#ifndef VEC_HPP
#define VEC_HPP

#include <SDL2/SDL_rect.h>
#include <ostream>

struct Vec2f {
    float x;
    float y;

    Vec2f operator+(const Vec2f &other) const
    {
        Vec2f newVec;
        newVec.x = x + other.x;
        newVec.y = y + other.y;
        return newVec;
    }

    Vec2f operator-(const Vec2f &other) const
    {
        Vec2f newVec;
        newVec.x = x - other.x;
        newVec.y = y - other.y;
        return newVec;
    }

    Vec2f &operator+=(const Vec2f &other)
    {
        x += other.x;
        y += other.y;
        return *this;
    }

    Vec2f &operator-=(const Vec2f &other)
    {
        x -= other.x;
        y -= other.y;
        return *this;
    }

    Vec2f operator*(int m) const
    {
        Vec2f newVec;
        newVec.x = x * m;
        newVec.y = y * m;
        return newVec;
    }

    Vec2f &operator*=(int m)
    {
        x *= m;
        y *= m;
        return *this;
    }

    operator SDL_Point()
    {
        return SDL_Point {static_cast<int>(x), static_cast<int>(y)};
    }
};

struct Vec2i {
    int x;
    int y;

    Vec2i operator+(const Vec2i &other) const
    {
        Vec2i newVec;
        newVec.x = x + other.x;
        newVec.y = y + other.y;
        return newVec;
    }

    Vec2i operator-(const Vec2i &other) const
    {
        Vec2i newVec;
        newVec.x = x - other.x;
        newVec.y = y - other.y;
        return newVec;
    }

    Vec2i &operator+=(const Vec2i &other)
    {
        x += other.x;
        y += other.y;
        return *this;
    }

    Vec2i &operator-=(const Vec2i &other)
    {
        x -= other.x;
        y -= other.y;
        return *this;
    }

    Vec2i operator*(int m) const
    {
        Vec2i newVec;
        newVec.x = x * m;
        newVec.y = y * m;
        return newVec;
    }

    Vec2i &operator*=(int m)
    {
        x *= m;
        y *= m;
        return *this;
    }

    bool operator==(const Vec2i &other)
    {
        return x == other.x && y == other.y;
    }

    bool operator!=(const Vec2i &other)
    {
        return x != other.x || y != other.y;
    }

    operator SDL_Point()
    {
        return SDL_Point {x, y};
    }
};


struct Vec2d {
    double x;
    double y;

    Vec2d operator+(const Vec2d &other) const
    {
        Vec2d newVec;
        newVec.x = x + other.x;
        newVec.y = y + other.y;
        return newVec;
    }

    Vec2d operator-(const Vec2d &other) const
    {
        Vec2d newVec;
        newVec.x = x - other.x;
        newVec.y = y - other.y;
        return newVec;
    }

    Vec2d &operator+=(const Vec2d &other)
    {
        x += other.x;
        y += other.y;
        return *this;
    }

    Vec2d &operator-=(const Vec2d &other)
    {
        x -= other.x;
        y -= other.y;
        return *this;
    }

    Vec2d operator*(int m) const
    {
        Vec2d newVec;
        newVec.x = x * m;
        newVec.y = y * m;
        return newVec;
    }

    Vec2d &operator*=(int m)
    {
        x *= m;
        y *= m;
        return *this;
    }

    Vec2d &operator+=(const Vec2i &other)
    {
        x += static_cast<double>(other.x);
        y += static_cast<double>(other.y);
        return *this;
    }

    bool operator==(const Vec2d &other)
    {
        return x == other.x && y == other.y;
    }

    bool operator!=(const Vec2d &other)
    {
        return x != other.x || y != other.y;
    }
};

inline std::ostream &operator<< (std::ostream &os, const Vec2d &v)
{
    os << "x: " << v.x << "\ty: " << v.y;
    return os;
}

#endif // VEC_HPP