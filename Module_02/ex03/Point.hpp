#if !defined(POINT_HPP_)
#define POINT_HPP_

#include "Fixed.hpp"

class Point {

	private:
		const Fixed		_x;
		const Fixed		_y;

	public:
		Point(void);
		Point(float, float);
		Point(const Point&);
		~Point();

		Point&			operator=(const Point&);
		float			getXValue(void) const;
		float			getYValue(void) const;
		Fixed			getX(void) const;
		Fixed			getY(void) const;

};

bool	bsp(Point const a, Point const b, Point const c, Point const point);

#endif // POINT_HPP_
