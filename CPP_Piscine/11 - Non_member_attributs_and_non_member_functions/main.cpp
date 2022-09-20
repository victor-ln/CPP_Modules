#include "Sample.class.hpp"

static void f0(void);
static void f1(void);

int	main(void) {
	std::cout << "Number of instances: " << Sample::getNbInst() << std::endl;
	f1();
	std::cout << "Number of instances: " << Sample::getNbInst() << std::endl;
	return (0);
}

static void f0(void) {
	Sample	instance;

	std::cout << "Number of instances: " << Sample::getNbInst() << std::endl;
}

static void f1(void) {
	Sample	instance;

	std::cout << "Number of instances: " << Sample::getNbInst() << std::endl;
	f0();
}
