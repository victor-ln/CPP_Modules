#ifndef SAMPLE1_CLASS_HPP
# define SAMPLE1_CLASS_HPP

#include <iostream>

struct Sample1 {

	char	a;
	int		b;
	float	c;

	Sample1(void);
	~Sample1(void);

	void	bar(void) const;
};

#endif
