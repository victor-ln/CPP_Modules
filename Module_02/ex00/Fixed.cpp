#include "Fixed.hpp"

Fixed::Fixed(void) {
	std::cout << "Default constructor called" << std::endl;
	this->_fixedNbValue = 0;
}

Fixed::Fixed(const Fixed& rightHandSide) {
	std::cout << "Copy constructor called" << std::endl;
	*this = rightHandSide;
}

Fixed::~Fixed(void) {
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

Fixed&	Fixed::operator=(const Fixed& rightHandSide) {
	std::cout << "Copy assignment operator called" << std::endl;
	this->_fixedNbValue = rightHandSide.getRawBits();
	return (*this);
}

const int Fixed::_fractionalBitNb = 8;
