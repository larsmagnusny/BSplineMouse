#ifndef BSPLINE_H
#define BSPLINE_H

#include <vector>
#include "vec2.h"

using namespace std;

namespace BSplineMouse
{
    class BSpline
    {
    public:
        BSpline();
        BSpline(const vector<Vec2>& controlPoints, const vector<double>& knots);

        double evaluateBasisFunction(unsigned int i, unsigned int p, double time);
        Vec2 evaluateSpline(unsigned int k, unsigned int degree, unsigned int i, double time);
        void makeRandomSpline();
        void makeRandomSplineBetweenTwoPoints(Vec2 p0, Vec2 p1);
        double randRange(double min, double max);
        unsigned int whichInterval(double time);
        Vec2 lerp(Vec2 start, Vec2 end, double time);
    private:
        int mDegree;
        int mSize;
        int mNumKnots;
        vector<double> mKnots;
        vector<Vec2> mControlPoints;

        // buffers for calculation
        Vec2 sum, ret;
        unsigned int i;
    };
}
#endif // BSPLINE_H
