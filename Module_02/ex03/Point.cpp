#include "Point.hpp"

Point::Point(void) : _x(0), _y(0) {
	std::cout << "Default constructor called" << std::endl;
}

Point::Point(const float x, const float y) : _x(x), _y(y) {
	std::cout << "Floats constructor called" << std::endl;
}

Point::Point(const Point& src) {
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
}

Point&	Point::operator=(const Point& src) {
	std::cout << "Copy assignment operator called" << std::endl;
	const_cast<Fixed&>(this->_x) = src.getX();
	const_cast<Fixed&>(this->_y) = src.getY();

	return (*this);
}

Point::~Point(void) {
	std::cout << "Destructor called" << std::endl;
}

float	Point::getXValue(void) const {
	return (this->_x.toFloat());
}

float	Point::getYValue(void) const {
	return (this->_y.toFloat());
}

Fixed  Point::getX(void) const {
	return (this->_x);
}

Fixed  Point::getY(void) const {
	return (this->_y);
}

