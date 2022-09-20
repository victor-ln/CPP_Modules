#include "Sample.class.hpp"

Sample::Sample(void) {
	std::cout << "Constructor Called" << std::endl;
	this->foo = 0;
}

Sample::~Sample(void) {
	std::cout << "Destructor Called" << std::endl;
}

void	Sample::bar( void ) const {
	std::cout << "Member function bar called" << std::endl;
}
