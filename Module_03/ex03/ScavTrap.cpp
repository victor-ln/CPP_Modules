#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void) : ClapTrap(void) {
	std::cout << "ScavTrap: Default Constructor called" << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name) {
	std::cout << "ScavTrap: Name constructor called" << std::endl;
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;
}

ScavTrap::ScavTrap(const ScavTrap& rightHandSide) : ClapTrap(rightHandSide) {
	std::cout << "ScavTrap: Copy constructor called" << std::endl;
	*this = rightHandSide;
}

ScavTrap::~ScavTrap(void) {
	std::cout << "ScavTrap: Destructor called" << std::endl;
}

ScavTrap&   ScavTrap::operator=(const ScavTrap& rightHandSide) {
	std::cout << "ScavTrap: Copy assignment operator called" << std::endl;
	this->_name = rightHandSide._name;
	this->_hitPoints = rightHandSide._hitPoints;
	this->_energyPoints = rightHandSide._energyPoints;
	this->_attackDamage = rightHandSide._attackDamage;
	return (*this);
}

void	ScavTrap::guardGate(void) {
	std::cout << "ScavTrap is in keeper mode" << std::endl;
}

void		ScavTrap::attack(const std::string& target) {
	if (!this->_hitPoints) {
		std::cout << "ScavTrap " << this->_name << " has no hit points" << std::endl;
		return ;
	}
	if (this->_energyPoints) {
		std::cout << "ScavTrap " << this->_name 
				<< " attacks " <<  target << ", causing " 
				<< this->_attackDamage << " points of damage!" << std::endl;
		this->_energyPoints--;
	}
	else
		std::cout << "ScavTrap " << this->_name << " has no energy points" << std::endl;
}
