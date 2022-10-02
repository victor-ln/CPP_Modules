/* Copyright © 2022 Victor Nunes, Licensed under the MIT License. */

#ifndef MODULE_01_EX03_INCLUDES_HUMANA_HPP_
#define MODULE_01_EX03_INCLUDES_HUMANA_HPP_

#include <iostream>
#include <string>

#include "./Weapon.hpp"

class HumanA {
 public:
    HumanA(std::string, Weapon&);
    HumanA(std::string, Weapon*);
    ~HumanA();

    void    attack(void) const;
    void    setWeapon(Weapon&);
    void    setWeapon(Weapon*);

 private:
    std::string    _name;
    Weapon*        _weapon;
};

#endif /* MODULE_01_EX03_INCLUDES_HUMANA_HPP_ */
