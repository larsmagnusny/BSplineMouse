#include "include/bspline.h"
#include <random>

namespace BSplineMouse
{
    BSpline::BSpline()
    {

    }

    BSpline::BSpline(const vector<Vec2> &controlPoints, const vector<double> &knots)
    {
        mControlPoints = controlPoints;
        mKnots = knots;
    }

    double BSpline::evaluateBasisFunction(unsigned int i, unsigned int p, double time)
    {
        if(p == 0)
        {
            if(time >= mKnots[i] && time < mKnots[i+1])
                return 1.;
            else
                return 0.;
        }
        else
        {
            double d1, d2, r1, r2, prev;

            d1 = time - mKnots[i];
            d2 = mKnots[i+p] - mKnots[i];

            prev = evaluateBasisFunction(i, p-1, time);

            r1 = prev*((d2 != 0.) ? d1/d2 : 0);

            d1 = mKnots[i+p+1] - time;
            d2 = mKnots[i+p+1] - mKnots[i+1];

            prev = evaluateBasisFunction(i+1, p-1, time);

            r2 = prev*((d2 != 0.) ? d1/d2 : 0);

            return r1 + r2;
        }
    }

    Vec2 BSpline::evaluateSpline(unsigned int k, unsigned int degree, unsigned int i, double time)
    {
        if(k == 0)
            return mControlPoints[i];
        else
        {
            double alpha = (time-mKnots[i])/(mKnots[i+degree+1-k]-mKnots[i]);
            return (evaluateSpline(k-1,degree, i-1, time)*(1-alpha )+evaluateSpline(k-1,degree, i, time)*alpha);
        }
    }

    void BSpline::makeRandomSpline()
    {
        unsigned int size = (rand() % 10) + 5;

        mControlPoints.reserve(size);
        mControlPoints.resize(size);

        for(unsigned int i = 0; i < size; i++)
            mControlPoints[i] = Vec2(rand() % 1980, rand() % 1080);
        unsigned int numKnots = size - 3;
        double delta = 1. / (numKnots+1);
        numKnots += 6;

        mKnots.reserve(numKnots);
        mKnots.resize(numKnots);

        unsigned int k = 0;
        for(int i = 0; i < 3; i++)
            mKnots[k++] = 0.;

        for(unsigned i = 0; i < size-3; i++)
            mKnots[k++] = delta*(i+1);

        for(int i = 0; i < 3; i++)
            mKnots[k++] = 1.;
    }

    void BSpline::makeRandomSplineBetweenTwoPoints(Vec2 p0, Vec2 p1)
    {
        Vec2 dir = p1-p0;

        Vec2 dirTan = dir.crossUp3D();
        dirTan.normalize();

        unsigned int size = 11;

        mControlPoints.reserve(size);
        mControlPoints.resize(size);

        mControlPoints[0] = p0;
        mControlPoints[1] = lerp(p0, p1, 0.1) + dirTan*randRange(-100, 100)*0.1;
        mControlPoints[2] = lerp(p0, p1, 0.2) + dirTan*randRange(-100, 100);
        mControlPoints[3] = lerp(p0, p1, 0.3) + dirTan*randRange(-100, 100);
        mControlPoints[4] = lerp(p0, p1, 0.4) + dirTan*randRange(-100, 100);
        mControlPoints[5] = lerp(p0, p1, 0.5) + dirTan*randRange(-100, 100);
        mControlPoints[6] = lerp(p0, p1, 0.6) + dirTan*randRange(-100, 100);
        mControlPoints[7] = lerp(p0, p1, 0.7) + dirTan*randRange(-100, 100);
        mControlPoints[8] = lerp(p0, p1, 0.8) + dirTan*randRange(-100, 100);
        mControlPoints[9] = lerp(p0, p1, 0.9) + dirTan*randRange(-100, 100)*0.1;
        mControlPoints[10] = p1;

        unsigned int numKnots = static_cast<unsigned int>(mControlPoints.size()) - 3;
        double delta = 1. / (numKnots+1);
        numKnots += 6;

        mKnots.reserve(numKnots);
        mKnots.resize(numKnots);

        unsigned int k = 0;
        for(int i = 0; i < 3; i++)
            mKnots[k++] = 0.;

        for(unsigned i = 0; i < size-3; i++)
            mKnots[k++] = delta*(i+1);

        for(int i = 0; i < 3; i++)
            mKnots[k++] = 1.;
    }

    double BSpline::randRange(double min, double max)
    {
        return ((max-min)*(static_cast<double>(rand()) / RAND_MAX)+min);
    }


    unsigned int BSpline::whichInterval(double time)
    {
        for(unsigned int i = 0; i < mKnots.size()-1; i++)
        {
            if(time >= mKnots[i] && time < mKnots[i+1])
                return i;
        }

        return 0;
    }

    Vec2 BSpline::lerp(Vec2 start, Vec2 end, double time)
    {
        return (start + (end-start)*time);
    }
}
