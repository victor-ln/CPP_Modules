#include "FragTrap.hpp"

FragTrap::FragTrap(void) : ClapTrap(void) {
	std::cout << "FragTrap: Default Constructor called" << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name) {
	std::cout << "FragTrap: Default constructor called" << std::endl;
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackDamage = 30;
}

FragTrap::FragTrap(FragTrap& src) : ClapTrap(src) {
	std::cout << "FragTrap: Copy constructor called" << std::endl;
	*this = src;
}

FragTrap::~FragTrap(void) {
	std::cout << "FragTrap: Destructor called" << std::endl;
}

FragTrap&   FragTrap::operator=(const FragTrap& rightHandSide) {
	this->_name = rightHandSide._name;
	this->_hitPoints = rightHandSide._hitPoints;
	this->_energyPoints = rightHandSide._energyPoints;
	this->_attackDamage = rightHandSide._attackDamage;
	return (*this);
}

void	FragTrap::highFivesGuys(void) {
	std::cout << "✋" << std::endl;
}
