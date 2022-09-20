#include "Sample.class.hpp"

int	main(void) {
	Sample  instance;

	instance.setFoo(42);
	std::cout << "instance.publicFoo: " << instance.getFoo() << std::endl;
	instance.setFoo(-42);
	std::cout << "instance.publicFoo: " << instance.getFoo() << std::endl;
	return (0);
}
