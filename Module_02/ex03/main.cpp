#include "Point.hpp"

int main(void)
{
	const Point		a(0, 0);
	const Point		b(20.0f, 0);
	const Point		c(10.0f, 30.0f);

	if (bsp(a, b, c, Point(15.0f, 15.0f)))
		std::cout << "Point is inside the triangle" << std::endl;
	else
		std::cout << "Point is outside the triangle" << std::endl;
	if (bsp(a, b, c, Point(15.0f, 29.9f)))
		std::cout << "Point is inside the triangle" << std::endl;
	else
		std::cout << "Point is outside the triangle" << std::endl;
	return (0);
}
