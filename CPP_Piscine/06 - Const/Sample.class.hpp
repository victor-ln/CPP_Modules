#ifndef SAMPLE_CLASS_HPP
# define SAMPLE_CLASS_HPP

#include <iostream>

class Sample {

	public:
		/* float		pi; */
		float const	pi; /* It must be initializated with the constructor */
		int			n;

		/* Sample( void ); */
		Sample( float const );
		~Sample( void );

		void	bar( void ) const;

		/*
		void	bar( void ); <-- It only works with non constant objects.
		*/
};

#endif
