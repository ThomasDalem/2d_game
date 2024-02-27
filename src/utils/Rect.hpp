#ifndef RECT_HPP
#define RECT_HPP

#include <ostream>

struct RectF {
    float x;
    float y;
    float width;
    float height;
};

inline std::ostream &operator<< (std::ostream &os, const RectF &rect)
{
    os << "x: " << rect.x
        << "\ty: " << rect.y
        << "\twidth: " << rect.width
        << "\theight: " << rect.height;
    return os;
}

struct RectI {
    int x;
    int y;
    int width;
    int height;
};

inline std::ostream &operator<< (std::ostream &os, const RectI &rect)
{
    os << "x: " << rect.x
        << "\ty: " << rect.y
        << "\twidth: " << rect.width
        << "\theight: " << rect.height;
    return os;
}

#endif // RECT_HPP