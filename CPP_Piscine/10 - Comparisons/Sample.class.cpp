#include "Sample.class.hpp"

Sample::Sample(int v) : _foo(v) {
	std::cout << "Constructor Called" << std::endl;
}

Sample::~Sample(void) {
	std::cout << "Destructor Called" << std::endl;
}

int		Sample::getFoo(void) const {
	return (this->_foo);
}

int		Sample::compare(Sample *ptr) const {
	if (this->getFoo() > ptr->getFoo())
		return (1);
	if (this->getFoo() < ptr->getFoo())
		return (-1);
	return (0);
}
