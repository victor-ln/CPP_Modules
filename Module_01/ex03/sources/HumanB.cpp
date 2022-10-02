/* Copyright © 2022 Victor Nunes, Licensed under the MIT License. */

#include "../includes/HumanB.hpp"

HumanB::HumanB(std::string name) {
    this->_name = name;
}

HumanB::~HumanB(void) {
    return;
}

void    HumanB::attack(void) const {
    std::cout << this->_name << " attacks with their " << \
                this->_weapon->getType() << std::endl;
}

void    HumanB::setWeapon(Weapon& newWeapon) {
    this->_weapon = &newWeapon;
}

void    HumanB::setWeapon(Weapon* newWeapon) {
    this->_weapon = newWeapon;
}
