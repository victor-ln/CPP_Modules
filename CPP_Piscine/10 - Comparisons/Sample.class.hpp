#ifndef SAMPLE_CLASS_HPP
# define SAMPLE_CLASS_HPP

#include <iostream>

class Sample {
	public:

		Sample(int v);
		~Sample(void);

		int		getFoo(void) const;
		int		compare(Sample *) const;

	private:
		int		_foo;
};

#endif
