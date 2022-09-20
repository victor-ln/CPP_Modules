#include "Sample1.class.hpp"

Sample1::Sample1( char x, int y, float z ) {
	std::cout << "Constructor called" << std::endl;
	this->a = x;
	std::cout << "this->a :" << this->a << std::endl;
	this->b = y;
	std::cout << "this->b :" << this->b << std::endl;
	this->c = z;
	std::cout << "this->c :" << this->c << std::endl;
}

Sample1::~Sample1( void ) {
	std::cout << "Destructor called" << std::endl;
}
