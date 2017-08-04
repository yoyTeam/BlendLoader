#include "yAnimationData.h"
#include "OgreMath.h"

#define SplineTOL                DBL_EPSILON
#define SplineAbs(x)            fabs(x)
#define SplineFuzzy( x )        (SplineAbs( x ) <= SplineTOL)
#define SplineEq(x)                ((x) >= (-SplineTOL) && (x) <= (1.+SplineTOL))
#define SplineFuzzyEq(x, y)        (SplineAbs(((x) - (y))) <= SplineTOL)
#define SplineMax( lhs, rhs )    ((lhs) < (rhs) ? (rhs) : (lhs))

double CubicRoot(const double d)
{
    static const double o3 = 1.0 / 3.0;
    return d > 0.0 ?  pow(d, o3)  :
           d < 0.0 ? -pow(-d, o3) : 0.0;
}

bool StepCubic(const float* P0, const float* P1, const float* P2, const float* P3, float time, double& cval)
{
    float ts = (P3[0] - P0[0]);
    if (ts <= 1.f)
        ts = 2.f;
    if (ts >= 60.f)
        ts = 60.f;


    const float step = (1.f / ts) / 4.f;
    // 240 max, anything else is choppy

    cval = 0.0;
    float s = 1.f, sc, sst;
    float t = 0.f, tc, tts;


    while (t <= 1.0)
    {
        sc =  s * s * s;
        tc =  t * t * t;
        sst = 3.f * s * s * t;
        tts = 3.f * t * t * s;

        if ((sc * P0[0] + sst * P1[0] + tts * P2[0] + tc * P3[0]) >= time)
        {
            cval = (sc * P0[1] + sst * P1[1] + tts * P2[1] + tc * P3[1]);
            return true;
        }

        t += step;
        s = 1.f - t;
    }
    return false;
}

float yBezierSpline::interpolate(const double& t,
                                     const double& p0,
                                     const double& p1,
                                     const double& p2,
                                     const double& p3) const
{
    double c0, c1, c2, c3;
    double t2 = t * t;
    double t3 = t2 * t;

    c0 = p0;
    c1 = -3.0 * p0 + 3.0 * p1;
    c2 = 3.0 * p0 - 6.0 * p1 + 3.0 * p2;
    c3 = -p0 + 3.0 * p1 - 3.0 * p2 + p3;

    return (float)(c0 + t * c1 + t2 * c2 + t3 * c3);
}

int yBezierSpline::solveRoots(const double& x,
                               const double p0,
                               const double p1,
                               const double p2,
                               const double p3,
                               double& s) const
{

    // Adapped from Graphics Gems
    // And from Graphics Gems IV
    // Roots3And4.c, solver.c
    // by Jochen Schwarze

    static const double o2    = 2.0 / 27.0;
    static const double o3    = 1.0 / 3.0;
    static const double tPI    = (4.0 * atan(1.0)) * o3;

    double a, b, c, d, p, q, aa, cp, ao3;
    double c0, c1, c2, c3;

    s = 0.0;

    c0 = p0 - x;
    c1 = -3.0 * p0 + 3.0 * p1;
    c2 = 3.0 * p0 - 6.0 * p1 + 3.0 * p2;
    c3 = -p0 + 3.0 * p1 - 3.0 * p2 + p3;

    if (m_interpMethod == yBezierSpline::BEZ_LINEAR)
    {
        // do linear
        if (SplineFuzzy(c1))
            return 0;

        s = -c0 / c1;
        return SplineEq(s) ? 1 : 0;
    }

    if (SplineFuzzy(c3))
    {
        if (!SplineFuzzy(c1))
            s = -c0 / c1;

        if (SplineEq(s))
            return 1;

        if (SplineFuzzy(c0))
            return 1;

        return 0;
    }


    // normal form:
    // x^3 + Ax^2 + Bx + C = 0

    a = c2 / c3;
    b = c1 / c3;
    c = c0 / c3;

    // substitute x = y - a/3 to eliminate quadric term:
    // x^3 +px + q = 0

    ao3 = a * o3;
    aa = a * a;

    p = o3 * (-o3 * aa + b);
    q = 0.5 * (o2 * a * aa - o3 * a * b + c);

    // use Cardano's formula
    cp = p * p * p;
    d = q * q + cp;

    if (SplineFuzzy(d))
    {
        if (SplineFuzzy(q))
        {
            // one triple solution
            s = 0.0;
            return 1;
        }
        else
        {
            double u = CubicRoot(-q);

            // one single and one double solution
            s = 2.0 * u;
            // try next
            if (!SplineEq(s - ao3))
                s = -u;
        }
    }
    else if (d < 0.0)
    {
        // three real solutions
        double phi = o3 * acos(-q / sqrt(-cp));
        double t = 2.0 * sqrt(-p);

        s = t * cos(phi);
        if (!SplineEq(s - ao3))
        {
            // try next
            s = -t *  cos(phi + tPI);
            if (!SplineEq(s - ao3))
                s = -t * cos(phi - tPI);
        }
    }
    else
    {
        // one real solution
        double S = sqrt(d);
        double u = CubicRoot(S - q);
        double v = -CubicRoot(S + q);
        s = u  + v;
    }

    // resubstitute
    s -= ao3;
    return SplineEq(s) ? 1 : 0;
}



void yBezierSpline::updateHandles(float* p0, float* p1, float* p2, float* p3) const
{
    float lh = SplineAbs((p0[0] - p1[0]) + (p3[0] - p2[0]));
    if (lh != 0.0)
    {
        if (lh > (p3[0] - p0[0]))
        {
            float f = (p3[0] - p0[0]) / lh;
            p1[0] = (p0[0] - f * abs((p0[0] - p1[0])));
            p1[1] = (p0[1] - f * abs((p0[1] - p1[1])));
            p2[0] = (p3[0] - f * abs((p3[0] - p2[0])));
            p2[1] = (p3[1] - f * abs((p3[1] - p2[1])));
        }
    }
}



float yBezierSpline::interpolate(float delta, float time) const
{
    int totvert = m_verts.size();
    float p0[2], p1[2], p2[2], p3[2];
    double r = 0.0;

    if (!totvert)
        return 0.f;

    // at the start
    if (m_verts[0].cp[0] >= time)  return m_verts[0].cp[1];

    // at the end
    if (m_verts[totvert-1].cp[0] <= time) return m_verts[totvert-1].cp[1];

    // find closest segment to time

    int segment = (int)(delta * (totvert - 1));
    while (segment && m_verts[segment].cp[0] > time)
        --segment;

    segment = SplineMax(segment, 0);

    for (int s = segment; s < (totvert - 1); ++s)
    {
        if (m_verts[s].cp[0] <= time && m_verts[s+1].cp[0] >= time)
        {
            if (m_interpMethod == BEZ_CONSTANT)
            {
                // take constant
                return m_verts[s+0].cp[1];
            }

            else if (m_interpMethod == BEZ_LINEAR)
            {
                float blend = ( m_verts[s+1].cp[0] - time ) / ( m_verts[s+1].cp[0] - m_verts[s].cp[0] );
                r = Ogre::Math::lerp( m_verts[s+1].cp[1], m_verts[s].cp[1], blend );
                return (float)r;
            }

            p0[0] = m_verts[s+0].cp[0]; p0[1] = m_verts[s+0].cp[1];
            p1[0] = m_verts[s+0].h2[0]; p1[1] = m_verts[s+0].h2[1];
            p2[0] = m_verts[s+1].h1[0]; p2[1] = m_verts[s+1].h1[1];
            p3[0] = m_verts[s+1].cp[0]; p3[1] = m_verts[s+1].cp[1];

            updateHandles(p0, p1, p2, p3);

            if (solveRoots(time, p0[0], p1[0], p2[0], p3[0], r))
                return interpolate(r, p0[1], p1[1], p2[1], p3[1]);
            else
            {
                //printf("Failed %f\n", r);
                if (StepCubic(p0, p1, p2, p3, time, r))
                    return (float)r;
            }
        }
    }
    return 0.f;
}
