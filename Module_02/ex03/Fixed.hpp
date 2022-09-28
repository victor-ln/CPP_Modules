#if !defined(FIXED_HPP_)
#define FIXED_HPP_

#include <iostream>
#include <cmath>

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

		bool	operator==(const Fixed&) const ;
		bool	operator!=(const Fixed&) const ;
		bool	operator>(const Fixed&) const ;
		bool	operator<(const Fixed&) const ;
		bool	operator<=(const Fixed&) const ;
		bool	operator>=(const Fixed&) const ;

		Fixed	operator+(const Fixed&) const ;
		Fixed	operator-(const Fixed&) const ;
		Fixed	operator*(const Fixed&) const ;
		Fixed	operator/(const Fixed&) const ;

		Fixed&	operator++(void);
		Fixed	operator++(int);
		Fixed&	operator--(void);
		Fixed	operator--(int);

		static const Fixed&	max(const Fixed&, const Fixed&);
		static const Fixed&	min(const Fixed&, const Fixed&);
		static Fixed&			max(Fixed&, Fixed&);
		static Fixed&			min(Fixed&, Fixed&);

		int		getRawBits(void) const;
		void	setRawBits(int const raw);
		float	toFloat(void) const;
		int		toInt(void) const;
};

std::ostream&	operator<<(std::ostream&, const Fixed&);

#endif // FIXED_HPP_
