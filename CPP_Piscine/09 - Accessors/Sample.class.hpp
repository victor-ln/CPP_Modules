#ifndef SAMPLE_CLASS_HPP
# define SAMPLE_CLASS_HPP

#include <iostream>

class Sample {
	public:

		Sample(void);
		~Sample(void);

		int		getFoo(void) const;
		void	setFoo(int v);

	private:
		int		_foo;
};

#endif
