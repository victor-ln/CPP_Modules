#ifndef SAMPLE2_CLASS_HPP
# define SAMPLE2_CLASS_HPP

/*
	Classes atributes and functions are set to private by default.
	This class will not compile.
*/

#include <iostream>

class Sample2 {

	char	a;
	int		b;
	float	c;

	Sample2(void);
	~Sample2(void);

	void	bar(void) const;
};

#endif
