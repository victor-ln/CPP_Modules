/* Copyright © 2022 Victor Nunes, Licensed under the MIT License. */

#ifndef MODULE_03_EX03_INCLUDES_FRAGTRAP_HPP_
#define MODULE_03_EX03_INCLUDES_FRAGTRAP_HPP_

#include <iostream>
#include <string>

#include "./ClapTrap.hpp"

class FragTrap : virtual public ClapTrap {
 public:
    FragTrap(void);
    FragTrap(FragTrap&);
    explicit FragTrap(std::string);
    ~FragTrap(void);

    FragTrap&   operator=(const FragTrap&);
    void        highFivesGuys(void) const;
};

#endif /* MODULE_03_EX03_INCLUDES_FRAGTRAP_HPP_ */
