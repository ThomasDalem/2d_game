#ifndef VEC_HPP
#define VEC_HPP

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
};

#endif // VEC_HPP