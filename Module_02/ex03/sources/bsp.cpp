/* Copyright © 2022 Victor Nunes, Licensed under the MIT License. */

#include "../includes/Fixed.hpp"
#include "../includes/Point.hpp"

static float calcTriangleArea(const Point& a, const Point& b, const Point& c);
static bool  isInVertex(const Point& a, const Point& b, const Point& point);
static float distance(const Point& a, const Point& b);
static float float_sqrt(float x);

bool    bsp(Point const a, Point const b, Point const c, Point const point) {
    if (isInVertex(a, b, point) || \
        isInVertex(a, c, point) || \
        isInVertex(b, c, point))
        return (false);

    float        pbcArea = calcTriangleArea(point, b, c);
    float        apcArea = calcTriangleArea(a, point, c);
    float        abpArea = calcTriangleArea(a, b, point);
    bool         negatives = (pbcArea < 0) | (apcArea < 0) | (abpArea < 0);
    bool         positives = (pbcArea > 0) | (apcArea > 0) | (abpArea > 0);

    return (!(negatives && positives));
}

static float calcTriangleArea(const Point& a, const Point& b, const Point& c) {
    return ((a.getXValue() * (b.getYValue() - c.getYValue()) + \
            b.getXValue() * (c.getYValue() - a.getYValue()) + \
            c.getXValue() * (a.getYValue() - b.getYValue())) / 2.0);
}

static bool isInVertex(const Point& a, const Point& b, const Point& c) {
    return (distance(a, c) + distance(c, b) == distance(a, b));
}

static float distance(const Point& a, const Point& b) {
    float   x = (a.getXValue() - b.getXValue());
    float   y = (a.getYValue() - b.getYValue());

    x *= x;
    y *= y;
    return (float_sqrt(x + y));
}

static float float_sqrt(float x) {
    float s, t;

    s = 1;
    t = x;
    while (s < t) {
        s *= 2;
        t /= 2;
    }
    do {
        t = s;
        s = (x / s + s) / 2;
    } while (s < t);
    return (t);
}
