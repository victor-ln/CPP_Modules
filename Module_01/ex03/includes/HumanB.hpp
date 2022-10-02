/* Copyright © 2022 Victor Nunes, Licensed under the MIT License. */

#ifndef MODULE_01_EX03_INCLUDES_HUMANB_HPP_
#define MODULE_01_EX03_INCLUDES_HUMANB_HPP_

#include <iostream>
#include <string>

#include "./Weapon.hpp"

class HumanB {
 public:
    explicit HumanB(std::string);
    ~HumanB();

    void    attack(void) const;
    void    setWeapon(Weapon&);
    void    setWeapon(Weapon*);

 private:
    std::string    _name;
    Weapon*        _weapon;
};

#endif /* MODULE_01_EX03_INCLUDES_HUMANB_HPP_ */
