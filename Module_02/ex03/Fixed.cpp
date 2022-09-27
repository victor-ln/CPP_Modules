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
	this->_fixedNbValue = nb * (1 << this->_fractionalBitNb) + (nb >= 0 ? 0.5 : -0.5);
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

float	Fixed::toFloat(void) const {
	return (this->_fixedNbValue / float(1 << this->_fractionalBitNb));
}

int		Fixed::toInt(void) const {
	return (this->_fixedNbValue >> this->_fractionalBitNb);
}

Fixed&	Fixed::operator=(const Fixed& rightHandSide) {
	std::cout << "Copy assignment operator called" << std::endl;
	this->_fixedNbValue = rightHandSide.getRawBits();
	return (*this);
}

std::ostream&	operator<<(std::ostream& out, const Fixed& c) {
	return (out << c.toFloat());
}

bool	Fixed::operator==(const Fixed& rightHandSide) const {
	return (this->_fixedNbValue == rightHandSide._fixedNbValue);
}

bool	Fixed::operator!=(const Fixed& rightHandSide) const {
	return (!(*this == rightHandSide));
}

bool	Fixed::operator<(const Fixed& rightHandSide) const {
	return (this->_fixedNbValue < rightHandSide._fixedNbValue);
}

bool	Fixed::operator>(const Fixed& rightHandSide) const {
	return (rightHandSide < *this);
}

bool	Fixed::operator>=(const Fixed& rightHandSide) const {
	return (!(*this < rightHandSide));
}

bool	Fixed::operator<=(const Fixed& rightHandSide) const {
	return (!(rightHandSide < *this));
}

Fixed	Fixed::operator+(const Fixed& rightHandSide) const {
	return ((this->_fixedNbValue + rightHandSide._fixedNbValue) / float(1 << this->_fractionalBitNb));
	/* return (this->toFloat() + rightHandSide.toFloat()); */
}

Fixed	Fixed::operator-(const Fixed& rightHandSide) const {
	return ((this->_fixedNbValue - rightHandSide._fixedNbValue) / float(1 << this->_fractionalBitNb));
	/* return (this->toFloat() - rightHandSide.toFloat()); */
}

Fixed	Fixed::operator*(const Fixed& rightHandSide) const {
	return (this->toFloat() * rightHandSide.toFloat());
}

Fixed	Fixed::operator/(const Fixed& rightHandSide) const {
	return (this->_fixedNbValue / float(rightHandSide._fixedNbValue));
	/* return (this->toFloat() / rightHandSide.toFloat()); */
}

Fixed&	Fixed::operator++(void) {
	/* this->_fixedNbValue += (1 << this->_fractionalBitNb); */
	this->_fixedNbValue++;
	return (*this);
}

Fixed	Fixed::operator++(int) {
	Fixed	tmp(*this);

	/* this->_fixedNbValue += (1 << this->_fractionalBitNb); */
	this->_fixedNbValue++;
	return (tmp);
}

Fixed&	Fixed::operator--(void) {
	/* this->_fixedNbValue -= (1 << this->_fractionalBitNb); */
	this->_fixedNbValue--;
	return (*this);
}

Fixed	Fixed::operator--(int) {
	Fixed	tmp(*this);

	/* this->_fixedNbValue -= (1 << this->_fractionalBitNb); */
	this->_fixedNbValue--;
	return (tmp);
}

const Fixed&	Fixed::max(const Fixed& x, const Fixed& y) {
	return ((x > y) ? x : y);
}

const Fixed&	Fixed::min(const Fixed& x, const Fixed& y) {
	return ((x < y) ? x : y);
}

Fixed&	Fixed::max(Fixed& x, Fixed& y) {
	return ((x > y) ? x : y);
}

Fixed&	Fixed::min(Fixed& x, Fixed& y) {
	return ((x < y) ? x : y);
}

const int Fixed::_fractionalBitNb = 8;
