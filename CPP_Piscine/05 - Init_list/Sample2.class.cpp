#include "Sample2.class.hpp"

Sample2::Sample2( char x, int y, float z ) : a(x), b(y), c(z) {
	std::cout << "Constructor called" << std::endl;
	std::cout << "this->a :" << this->a << std::endl;
	std::cout << "this->b :" << this->b << std::endl;
	std::cout << "this->c :" << this->c << std::endl;
}

Sample2::~Sample2( void ) {
	std::cout << "Destructor called" << std::endl;
}
