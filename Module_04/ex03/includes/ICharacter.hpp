/* Copyright © 2022 Victor Nunes, Licensed under the MIT License. */

#ifndef MODULE_04_EX03_INCLUDES_ICHARACTER_HPP_
#define MODULE_04_EX03_INCLUDES_ICHARACTER_HPP_

#include <iostream>
#include <string>

#include "./AMateria.hpp"

class AMateria;

class ICharacter {
 public:
    virtual ~ICharacter(void) {}

    virtual const std::string& getName(void) const = 0;
    virtual void equip(AMateria* m) = 0;
    virtual void unequip(int idx) = 0;
    virtual void use(int idx, const ICharacter& target) = 0;
};

#endif /* MODULE_04_EX03_INCLUDES_ICHARACTER_HPP_ */
