#ifndef SAMPLE_CLASS_HPP
# define SAMPLE_CLASS_HPP

#include <iostream>

class Sample {
	public:
		int		publicFoo;

		Sample(void);
		~Sample(void);

		static int	getNbInst(void);

	private:
		static int		_nbInst;
};

#endif
