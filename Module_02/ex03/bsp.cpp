#include "Fixed.hpp"
#include "Point.hpp"

float	calcTriangleArea(const Point& a, const Point& b, const Point& c) {
	return ((a.getXValue() * (b.getYValue() - c.getYValue()) + \
			b.getXValue() * (c.getYValue() - a.getYValue()) + \
			c.getXValue() * (a.getYValue() - b.getYValue())) / 2.0);
}

/*
	Line:
		a = (2, 0)
		b = (1, 3)
	point = (1.5, 1.5)

	isInVertex() Fomula:
		(pointY - aY) / (bY - aY) == (pointX - aX) / (bX - aY)

	(pointY - aY)	= 1.5
	(bY - aY)		= 3

	1.5 / 3 = 0.5

	(pointX - aX)	= -0.5
	(bX - aX)		= -1

	-0,5 / -1 == 0.5

	(0.5 == 0.5)
*/

bool	isInVertex(const Point& a, const Point& b, const Point& point) {
	return (((point.getYValue() - a.getYValue()) / (b.getYValue() - a.getYValue())) == \
			((point.getXValue() - a.getXValue()) / (b.getXValue() - a.getXValue())));
}

bool	bsp(Point const a, Point const b, Point const c, Point const point) {
	if (isInVertex(a, b, point) || isInVertex(a, c, point) || isInVertex(b, c, point))
		return (false);
	float		abcArea = calcTriangleArea(a, b, c);
	float		pbcArea = calcTriangleArea(point, b, c);
	float		apcArea = calcTriangleArea(a, point, c);
	float		abpArea = calcTriangleArea(a, b, point);

	return (abcArea == (pbcArea + apcArea + abpArea));
}
