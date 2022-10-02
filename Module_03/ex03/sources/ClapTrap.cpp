/* Copyright © 2022 Victor Nunes, Licensed under the MIT License. */

#include "../includes/ClapTrap.hpp"

ClapTrap::ClapTrap(void) {
    std::cout << "ClapTrap: Default Constructor called" << std::endl;
    this->_hitPoints = 10;
    this->_energyPoints = 10;
    this->_attackDamage = 0;
}

ClapTrap::ClapTrap(std::string name) {
    std::cout << "ClapTrap: Name Constructor called" << std::endl;
    this->_name = name;
    this->_hitPoints = 10;
    this->_energyPoints = 10;
    this->_attackDamage = 0;
}

ClapTrap::ClapTrap(const ClapTrap& rightHandSide) {
    std::cout << "ClapTrap: Copy constructor called" << std::endl;
    *this = rightHandSide;
}

ClapTrap::~ClapTrap(void) {
    std::cout << "ClapTrap: Destructor called" << std::endl;
}

ClapTrap&   ClapTrap::operator=(const ClapTrap& rightHandSide) {
    std::cout << "ClapTrap: Copy assignment operator called" << std::endl;
    this->_name = rightHandSide._name;
    this->_hitPoints = rightHandSide._hitPoints;
    this->_energyPoints = rightHandSide._energyPoints;
    this->_attackDamage = rightHandSide._attackDamage;
    return (*this);
}

void    ClapTrap::attack(const std::string& target) {
    std::cout << "ClapTrap " << this->_name;
    if (!this->_hitPoints) {
        std::cout << " has no hit points" << std::endl;
        return;
    }
    if (this->_energyPoints) {
        std::cout << " attacks " <<  target << ", causing "
                << this->_attackDamage << " points of damage!" << std::endl;
        this->_energyPoints--;
    } else {
        std::cout << " has no energy points" << std::endl;
    }
}

void    ClapTrap::takeDamage(unsigned int amount) {
    std::cout << "ClapTrap " << this->_name;
    if (!this->_hitPoints) {
        std::cout << " has no hit points" << std::endl;
        return;
    }
    std::cout << " took " << amount << " points of damage!" << std::endl;
    if (amount > this->_hitPoints)
        amount = this->_hitPoints;
    this->_hitPoints -= amount;
}

void    ClapTrap::beRepaired(unsigned int amount) {
    std::cout << "ClapTrap " << this->_name;
    if (!this->_hitPoints) {
        std::cout << " has no hit points" << std::endl;
        return;
    }
    if (this->_energyPoints && this->_hitPoints) {
        std::cout << " repairs " <<  amount << " hit points" << std::endl;
        this->_hitPoints += amount;
        this->_energyPoints--;
    } else {
        std::cout << " has no energy points" << std::endl;
    }
}

unsigned int    ClapTrap::getHitPoints(void) const {
    return (this->_hitPoints);
}

unsigned int    ClapTrap::getEnergyPoints(void) const {
    return (this->_energyPoints);
}

unsigned int    ClapTrap::getAttackDamage(void) const {
    return (this->_attackDamage);
}
