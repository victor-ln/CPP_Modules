#include "Sample.class.hpp"

Sample::Sample(void) {
	std::cout << "Constructor Called" << std::endl;
	Sample::_nbInst++;
}

Sample::~Sample(void) {
	std::cout << "Destructor Called" << std::endl;
	Sample::_nbInst--;
}

int		Sample::getNbInst(void) {
	return (Sample::_nbInst);
}

/*
	The only way to initialize a non member attribute 
	(static attribute) is outside the class.
*/

int		Sample::_nbInst = 0;
