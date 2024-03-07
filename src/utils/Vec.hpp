#ifndef VEC_HPP
#define VEC_HPP

#include <SDL2/SDL_rect.h>
#include <ostream>

struct Vec2d;

struct Vec2f {
    float x;
    float y;

    Vec2f operator+(const Vec2f &other) const;
    Vec2f operator-(const Vec2f &other) const;
    Vec2f operator*(int m) const;

    Vec2f &operator+=(const Vec2f &other);
    Vec2f &operator-=(const Vec2f &other);
    Vec2f &operator*=(int m);

    bool operator==(const Vec2f &other);
    bool operator!=(const Vec2f &other);

    operator SDL_Point();
};

struct Vec2i {
    int x;
    int y;

    Vec2i operator+(const Vec2i &other) const;
    Vec2i operator-(const Vec2i &other) const;
    Vec2i operator*(int m) const;

    Vec2i &operator+=(const Vec2i &other);
    Vec2i &operator+=(const Vec2d &other);
    Vec2i &operator-=(const Vec2i &other);
    Vec2i &operator*=(int m);

    bool operator==(const Vec2i &other);
    bool operator!=(const Vec2i &other);

    operator SDL_Point();
};


struct Vec2d {
    double x;
    double y;

    Vec2d operator+(const Vec2d &other) const;
    Vec2d operator-(const Vec2d &other) const;
    Vec2d operator*(int m) const;

    Vec2d &operator+=(const Vec2d &other);
    Vec2d &operator+=(const Vec2i &other);
    Vec2d &operator-=(const Vec2d &other);
    Vec2d &operator*=(int m);

    bool operator==(const Vec2d &other);
    bool operator!=(const Vec2d &other);
};

inline std::ostream &operator<< (std::ostream &os, const Vec2f &v)
{
    os << "x: " << v.x << "\ty: " << v.y;
    return os;
}

inline std::ostream &operator<< (std::ostream &os, const Vec2i &v)
{
    os << "x: " << v.x << "\ty: " << v.y;
    return os;
}

inline std::ostream &operator<< (std::ostream &os, const Vec2d &v)
{
    os << "x: " << v.x << "\ty: " << v.y;
    return os;
}

#endif // VEC_HPP