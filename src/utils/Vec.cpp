#include "Vec.hpp"

/*******************/
/****** Vec2f ******/
/*******************/
Vec2f Vec2f::operator+(const Vec2f &other) const
{
    Vec2f newVec;
    newVec.x = x + other.x;
    newVec.y = y + other.y;
    return newVec;
}

Vec2f Vec2f::operator-(const Vec2f &other) const
{
    Vec2f newVec;
    newVec.x = x - other.x;
    newVec.y = y - other.y;
    return newVec;
}

Vec2f &Vec2f::operator+=(const Vec2f &other)
{
    x += other.x;
    y += other.y;
    return *this;
}

Vec2f &Vec2f::operator-=(const Vec2f &other)
{
    x -= other.x;
    y -= other.y;
    return *this;
}

Vec2f Vec2f::operator*(int m) const
{
    Vec2f newVec;
    newVec.x = x * m;
    newVec.y = y * m;
    return newVec;
}

Vec2f &Vec2f::operator*=(int m)
{
    x *= m;
    y *= m;
    return *this;
}

Vec2f::operator SDL_Point()
{
    return SDL_Point {static_cast<int>(x), static_cast<int>(y)};
}

bool Vec2f::operator==(const Vec2f &other)
{
    return x == other.x && y == other.y;
}

bool Vec2f::operator!=(const Vec2f &other)
{
    return x != other.x || y != other.y;
}

/*******************/
/****** Vec2i ******/
/*******************/
Vec2i Vec2i::operator+(const Vec2i &other) const
{
    Vec2i newVec;
    newVec.x = x + other.x;
    newVec.y = y + other.y;
    return newVec;
}

Vec2i Vec2i::operator-(const Vec2i &other) const
{
    Vec2i newVec;
    newVec.x = x - other.x;
    newVec.y = y - other.y;
    return newVec;
}

Vec2i &Vec2i::operator+=(const Vec2i &other)
{
    x += other.x;
    y += other.y;
    return *this;
}

Vec2i &Vec2i::operator+=(const Vec2d &other)
{
    x += static_cast<int>(other.x);
    y += static_cast<int>(other.y);
    return *this;
}

Vec2i &Vec2i::operator-=(const Vec2i &other)
{
    x -= other.x;
    y -= other.y;
    return *this;
}

Vec2i Vec2i::operator*(int m) const
{
    Vec2i newVec;
    newVec.x = x * m;
    newVec.y = y * m;
    return newVec;
}

Vec2i &Vec2i::operator*=(int m)
{
    x *= m;
    y *= m;
    return *this;
}

bool Vec2i::operator==(const Vec2i &other)
{
    return x == other.x && y == other.y;
}

bool Vec2i::operator!=(const Vec2i &other)
{
    return x != other.x || y != other.y;
}

Vec2i::operator SDL_Point()
{
    return SDL_Point {x, y};
}

/*******************/
/****** Vec2d ******/
/*******************/
Vec2d Vec2d::operator+(const Vec2d &other) const
{
    Vec2d newVec;
    newVec.x = x + other.x;
    newVec.y = y + other.y;
    return newVec;
}

Vec2d Vec2d::operator-(const Vec2d &other) const
{
    Vec2d newVec;
    newVec.x = x - other.x;
    newVec.y = y - other.y;
    return newVec;
}

Vec2d &Vec2d::operator+=(const Vec2d &other)
{
    x += other.x;
    y += other.y;
    return *this;
}

Vec2d &Vec2d::operator-=(const Vec2d &other)
{
    x -= other.x;
    y -= other.y;
    return *this;
}

Vec2d Vec2d::operator*(int m) const
{
    Vec2d newVec;
    newVec.x = x * m;
    newVec.y = y * m;
    return newVec;
}

Vec2d &Vec2d::operator*=(int m)
{
    x *= m;
    y *= m;
    return *this;
}

Vec2d &Vec2d::operator+=(const Vec2i &other)
{
    x += static_cast<double>(other.x);
    y += static_cast<double>(other.y);
    return *this;
}

bool Vec2d::operator==(const Vec2d &other)
{
    return x == other.x && y == other.y;
}

bool Vec2d::operator!=(const Vec2d &other)
{
    return x != other.x || y != other.y;
}