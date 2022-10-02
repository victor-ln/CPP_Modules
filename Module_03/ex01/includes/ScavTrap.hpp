/* Copyright © 2022 Victor Nunes, Licensed under the MIT License. */

#ifndef MODULE_03_EX01_INCLUDES_SCAVTRAP_HPP_
#define MODULE_03_EX01_INCLUDES_SCAVTRAP_HPP_

#include <iostream>
#include <string>

#include "./ClapTrap.hpp"

class ScavTrap : public ClapTrap {
 public:
    ScavTrap(void);
    ScavTrap(const ScavTrap&);
    explicit ScavTrap(std::string);
    ~ScavTrap(void);

    ScavTrap&   operator=(const ScavTrap&);
    void        guardGate(void);
    void        attack(const std::string& target);
};

#endif /* MODULE_03_EX01_INCLUDES_SCAVTRAP_HPP_ */
