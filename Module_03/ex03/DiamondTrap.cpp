#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(void) : ClapTrap(), ScavTrap(), FragTrap() {
	std::cout << "DiamondTrap: Default constructor called" << std::endl;
	ScavTrap	tmp;
	this->_energyPoints = tmp.getEnergyPoints();
}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name"), ScavTrap(name), FragTrap(name) {
	std::cout << "DiamondTrap: Name constructor called" << std::endl;
	this->_name = name;
	ScavTrap	tmp(name);
	this->_energyPoints = tmp.getEnergyPoints();
}

DiamondTrap::DiamondTrap(DiamondTrap& src) : ClapTrap(src), ScavTrap(src), FragTrap(src) {
	std::cout << "DiamondTrap: Copy constructor called" << std::endl;
	*this = src;
}

DiamondTrap::~DiamondTrap(void) {
	std::cout << "DiamondTrap: Destructor called" << std::endl;
}

DiamondTrap&	DiamondTrap::operator=(const DiamondTrap& rightHandSide) {
	std::cout << "DiamondTrap: Copy assignment operator called" << std::endl;
	ClapTrap::_name = rightHandSide._name + "_clap_name";
	this->_name = rightHandSide._name;
	this->_hitPoints = rightHandSide._hitPoints;
	this->_attackDamage = rightHandSide._attackDamage;
	this->_energyPoints = rightHandSide._energyPoints;
	return (*this);
}

void DiamondTrap::whoAmI(void) {
	std::cout << "Diamond name: " << this->_name << std::endl;
	std::cout << "ClapTrap name: " << ClapTrap::_name << std::endl;
}
