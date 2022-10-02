/* Copyright © 2022 Victor Nunes, Licensed under the MIT License. */

#ifndef MODULE_02_EX03_INCLUDES_POINT_HPP_
#define MODULE_02_EX03_INCLUDES_POINT_HPP_

#include <iostream>

#include "./Fixed.hpp"

class Point {
 public:
    Point(void);
    Point(float, float);
    Point(const Point&);
    ~Point(void);

    Point&           operator=(const Point&);
    float            getXValue(void) const;
    float            getYValue(void) const;
    Fixed            getX(void) const;
    Fixed            getY(void) const;

 private:
    const Fixed        _x;
    const Fixed        _y;
};

bool    bsp(Point const a, Point const b, Point const c, Point const point);

#endif /* MODULE_02_EX03_INCLUDES_POINT_HPP_ */
