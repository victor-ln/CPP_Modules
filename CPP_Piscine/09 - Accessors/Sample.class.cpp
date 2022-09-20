#include "Sample.class.hpp"

Sample::Sample(void) {
	std::cout << "Constructor Called" << std::endl;
	this->_foo = 0;
	std::cout << "this->_foo: " << this->_foo << std::endl;
}

Sample::~Sample(void) {
	std::cout << "Destructor Called" << std::endl;
}

int		Sample::getFoo(void) const {
	return (this->_foo);
}

void	Sample::setFoo(int v) {
	if (v >= 0)
		this->_foo = v;
}
