#include "Sample.class.hpp"

int	main(void) {
	/*
		Constant objects needs a constructor to be compiled.
		If the constructor doesn't initialize the variables, 
		the compiler initialize them if these variables are not const. 
		All const variables must be initialized manually.
	*/
	/* const Sample	instance2; */
	Sample			instance(3.1415f);

	/* instance2.bar(); */
	instance.bar();

	return (0);
}
