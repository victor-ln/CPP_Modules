#include "Sample.class.hpp"

int	main(void) {
	Sample  instance;
	Sample  *instanceptr = &instance;
	int		Sample::*ptr;
	void	(Sample::*func)(void) const;

	ptr = &Sample::foo;
	func = &Sample::bar;
	std::cout << "Value of member foo: " << instance.foo << std::endl;
	instance.*ptr = 42;
	std::cout << "Value of member foo: " << instance.foo << std::endl;
	instanceptr->*ptr = 84;
	std::cout << "Value of member foo: " << instance.foo << std::endl;
	(instance.*func)();
	(instanceptr->*func)();
	return (0);
}
