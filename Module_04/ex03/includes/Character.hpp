/* Copyright © 2022 Victor Nunes, Licensed under the MIT License. */

#ifndef MODULE_04_EX03_INCLUDES_CHARACTER_HPP_
#define MODULE_04_EX03_INCLUDES_CHARACTER_HPP_

#include <iostream>
#include <string>

#include "./AMateria.hpp"
#include "./Dump.hpp"
#include "./ICharacter.hpp"

class Character : public ICharacter {
 public:
    Character(void);
    Character(const Character&);
    explicit Character(const std::string&);
    ~Character(void);

    Character&  operator=(const Character&);

    const std::string& getName(void) const;
    void equip(AMateria* m);
    void unequip(int idx);
    void use(int idx, const ICharacter& target);

 private:
    Dump         dump;
    AMateria     *_inventory[4];
    std::string  _name;
};

#endif /* MODULE_04_EX03_INCLUDES_CHARACTER_HPP_ */
