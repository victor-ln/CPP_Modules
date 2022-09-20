#include "Sample1.class.hpp"

Sample1::Sample1(void) {
	std::cout << "Constructor called" << std::endl;
}

Sample1::~Sample1(void) {
	std::cout << "Destructor called" << std::endl;
}

void	Sample1::bar(void) const {
	std::cout << "Member function bar called" << std::endl;
}
