#include "Fixed.hpp"

Fixed::Fixed() {
	std::cout << "Default constructor called" << std::endl;
	this->_fixedNbValue = 0;
}

Fixed::Fixed(int nb) {
	std::cout << "Int constructor called" << std::endl;
	this->_fixedNbValue = nb << this->_fractionalBitNb;
}

Fixed::Fixed(float nb) {
	std::cout << "Float constructor called" << std::endl;
	this->_fixedNbValue = nb * float(1 << this->_fractionalBitNb) + (nb >= 0 ? 0.5 : -0.5);
}

Fixed::Fixed(const Fixed& src) {
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
}

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void) const {
	std::cout << "getRawBits member function called" << std::endl;
	return (this->_fixedNbValue);
}

void	Fixed::setRawBits(int const raw) {
	std::cout << "setRawBits member function called" << std::endl;
	this->_fixedNbValue = raw;
}

void	Fixed::operator=(const Fixed& src) {
	std::cout << "Copy assignment operator called" << std::endl;
	this->_fixedNbValue = src.getRawBits();
}

std::ostream&	operator<<(std::ostream& out, const Fixed& c) {
	return (out << c.toFloat());
}

float	Fixed::toFloat(void) const {
	return (this->_fixedNbValue / float(1 << this->_fractionalBitNb));
}

int		Fixed::toInt(void) const {
	return (this->_fixedNbValue >> this->_fractionalBitNb);
}

const int Fixed::_fractionalBitNb = 8;
