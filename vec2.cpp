#include "include/vec2.h"
#include <cmath>

namespace BSplineMouse
{
    Vec2::Vec2(double _x, double _y) : x{_x}, y{_y}
    {

    }

    void Vec2::operator+=(Vec2 other){ x += other.x; y += other.y; }

    Vec2 Vec2::operator+(const Vec2& other){ return Vec2(x + other.x, y + other.y); }
    Vec2 Vec2::operator-(Vec2 other){ return Vec2(x - other.x, y - other.y); }

    Vec2 Vec2::operator*(Vec2 other)
    {
        return Vec2(x + other.x, y + other.y);
    }
    Vec2 Vec2::operator*(const Vec2& other){ return Vec2(x * other.x, y * other.y); }

    Vec2 Vec2::operator*(Vec2 *other)
    {
        return Vec2(x + other->x, y + other->y);
    }
    Vec2 Vec2::operator*(double other){ return Vec2(other*x, other*y); }

    Vec2 Vec2::crossUp3D()
    {
        return Vec2(y, x);
    }

    void Vec2::normalize()
    {
        double length = std::sqrt(x*x + y*y);

        if(length != 0.)
        {
            x = x/length;
            y = y/length;
        }
        else
        {
            x = 0.;
            y = 0.;
        }
    }
}
