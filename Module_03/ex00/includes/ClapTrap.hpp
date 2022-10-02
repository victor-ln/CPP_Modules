/* Copyright © 2022 Victor Nunes, Licensed under the MIT License. */

#ifndef MODULE_03_EX00_INCLUDES_CLAPTRAP_HPP_
#define MODULE_03_EX00_INCLUDES_CLAPTRAP_HPP_

#include <iostream>
#include <string>

class ClapTrap {
 public:
    ClapTrap(void);
    ClapTrap(const ClapTrap&);
    explicit ClapTrap(std::string);
    ~ClapTrap(void);

    ClapTrap&       operator=(const ClapTrap&);

    void            attack(const std::string& target);
    void            takeDamage(unsigned int amount);
    void            beRepaired(unsigned int amount);
    unsigned int    getHitPoints(void) const;
    unsigned int    getEnergyPoints(void) const;
    unsigned int    getAttackDamage(void) const;

 private:
    std::string     _name;
    unsigned int    _hitPoints;
    unsigned int    _energyPoints;
    unsigned int    _attackDamage;
};

#endif /* MODULE_03_EX00_INCLUDES_CLAPTRAP_HPP_ */
