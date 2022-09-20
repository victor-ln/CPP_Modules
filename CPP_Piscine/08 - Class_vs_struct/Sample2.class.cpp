#include "Sample2.class.hpp"

Sample2::Sample2(void) {
	std::cout << "Constructor called" << std::endl;
}

Sample2::~Sample2(void) {
	std::cout << "Destructor called" << std::endl;
}

void	Sample2::bar(void) const {
	std::cout << "Member function bar called" << std::endl;
}
