#include "Sample.class.hpp"

Sample::Sample( void ) {
	std::cout << "Constructor called" << std::endl;
}

Sample::~Sample( void ) {
	std::cout << "Destructor called" << std::endl;
}

void	Sample::bar( void ) {
	std::cout << "Member function bar called" << std::endl;
}
