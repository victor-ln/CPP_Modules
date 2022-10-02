/* Copyright © 2022 Victor Nunes, Licensed under the MIT License. */

#ifndef MODULE_03_EX03_INCLUDES_DIAMONDTRAP_HPP_
#define MODULE_03_EX03_INCLUDES_DIAMONDTRAP_HPP_

#include <iostream>
#include <string>

#include "./ClapTrap.hpp"
#include "./FragTrap.hpp"
#include "./ScavTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap {
 public:
    DiamondTrap(void);
    DiamondTrap(DiamondTrap&);
    explicit DiamondTrap(std::string);
    ~DiamondTrap(void);

    DiamondTrap&    operator=(const DiamondTrap&);
    void            whoAmI(void) const;

 private:
    std::string        _name;
};

#endif /* MODULE_03_EX03_INCLUDES_DIAMONDTRAP_HPP_ */
