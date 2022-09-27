#include "Fixed.hpp"
#include <cstdio>

int main( void ) {
	Fixed			a(1);
	Fixed			b(Fixed(5.05f) * Fixed(2));

	std::cout << std::endl;
	std::cout << "a: " << a << std::endl;
	std::cout << "b: " << b << std::endl;
	std::cout << std::endl << "++a: " << ++a << std::endl;
	std::cout << "a: " << a << std::endl;
	std::cout << "a++: " << a++ << std::endl;
	std::cout << "a: " << a << std::endl;
	std::cout << "b: " << b << std::endl;
	std::cout << std::endl;
	std::cout << "Fixed::max(a, b): " << Fixed::max(a, b) << std::endl;
	std::cout << "Fixed::min(a, b): " << Fixed::min(a, b) << std::endl;
	std::cout << std::endl << "(a + b)" << (a + b) << std::endl;
	std::cout << std::endl << "(a - b)" << (a - b) << std::endl;
	std::cout << std::endl << "(a * b)" << (a * b) << std::endl;
	std::cout << std::endl << "(a / b)" << (a / b) << std::endl;
	std::cout << std::endl;

	a = 12;
	b = 5;
	std::cout << "a: " << a << std::endl;
	std::cout << "b: " << b << std::endl;
	std::cout << std::endl << "(a + b)" << (a + b) << std::endl;
	std::cout << std::endl << "(a - b)" << (a - b) << std::endl;
	std::cout << std::endl << "(a * b)" << (a * b) << std::endl;
	std::cout << std::endl << "(a / b)" << (a / b) << std::endl;
	std::cout << std::endl;

	a = 5.1f;
	b = 5;
	std::cout << std::endl;
	std::cout << "a is " << a.toInt() << " as integer" << std::endl;
	std::cout << "b is " << b.toInt() << " as integer" << std::endl;
	std::cout << "(a >= b) : " << (a >= b) << std::endl;
	std::cout << "(a <= b) : " << (a <= b) << std::endl;
	std::cout << "(a == b) : " << (a == b) << std::endl;
	std::cout << "(a != b) : " << (a != b) << std::endl;
	std::cout << std::endl;
	return (0);
}

/*
	Rawbits decimal ==> 2586
	Rawbits binary ==> 101000011010

	1010.00011010
	10 + (2 ^ -4) + (2 ^ -5) + (2 ^ -7) ==> 10.1015625 =~ 10.16

	Rawbits decimal ==> 256
	Rawbits binary ==> 100000000

	1.00000000 ==> 1
	(2 ^ 0) ==> 1

	Rawbits decimal ==> 77
	Rawbits binary ==> 01001101

	0.01001101 ==> 1
	(2 ^ -2) + (2 ^ -5) + (2 ^ -6) + (2 ^ -8)

	0.25 + 0.03125 + 0.015625 + 0.00390625 ==> 0.30078125

*/
