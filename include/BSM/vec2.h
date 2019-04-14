#ifndef VEC2_H
#define VEC2_H

namespace BSplineMouse
{
    class Vec2
    {
    public:
        Vec2(double _x = 0., double _y = 0.);

        void operator+=(Vec2 other);
        Vec2 operator+(const Vec2& other);
        Vec2 operator-(Vec2 other);
        Vec2 operator*(Vec2 other);
        Vec2 operator*(const Vec2& other);
        Vec2 operator*(Vec2* other);
        Vec2 operator*(double other);
        Vec2 crossUp3D();
        double length();

        void normalize();

        double x;
        double y;
    };
}
#endif // VEC2_H
