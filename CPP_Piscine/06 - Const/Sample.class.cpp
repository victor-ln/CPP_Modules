#include "Sample.class.hpp"

/*
Sample::Sample( void ) {
	std::cout << "Constructor called" << std::endl;
}
*/

Sample::Sample( float const f ) : pi(f), n(42) {
	std::cout << "Constructor called" << std::endl;
}

Sample::~Sample( void ) {
	std::cout << "Destructor called" << std::endl;
}

/*
	Const member functions are those functions which are 
	denied permission to change the values of the data members of their class.
*/

void	Sample::bar( void ) const {
	std::cout << "this->pi :" << this->pi << std::endl;
	std::cout << "this->n :" << this->n << std::endl;

	/* This code below doesn't compile: */
	/* this->n++; */
	/* g++: error: increment of member ‘Sample::n’ in read-only object */
}
