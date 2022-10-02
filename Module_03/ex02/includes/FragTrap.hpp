/* Copyright © 2022 Victor Nunes, Licensed under the MIT License. */

#ifndef MODULE_03_EX02_INCLUDES_FRAGTRAP_HPP_
#define MODULE_03_EX02_INCLUDES_FRAGTRAP_HPP_

#include <iostream>
#include <string>

#include "./ClapTrap.hpp"

class FragTrap : public ClapTrap {
 public:
    FragTrap(void);
    FragTrap(FragTrap&);
    explicit FragTrap(std::string);
    ~FragTrap(void);

    FragTrap&   operator=(const FragTrap&);
    void        highFivesGuys(void);
};

#endif /* MODULE_03_EX02_INCLUDES_FRAGTRAP_HPP_ */
