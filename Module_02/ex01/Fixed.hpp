#if !defined(FIXED_HPP_)
#define FIXED_HPP_

#include <iostream>

class Fixed {

	private:
		int					_fixedNbValue;
		static const int	_fractionalBitNb;

	public:
		Fixed(void);
		Fixed(int);
		Fixed(float);
		Fixed(const Fixed&);
		~Fixed(void);

		Fixed&	operator=(const Fixed&);
		int		getRawBits(void) const;
		void	setRawBits(int const raw);
		float	toFloat(void) const;
		int		toInt(void) const;
};

std::ostream&	operator<<(std::ostream&, const Fixed&);

#endif // FIXED_HPP_
