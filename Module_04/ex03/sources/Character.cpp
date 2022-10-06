/* Copyright © 2022 Victor Nunes, Licensed under the MIT License. */

#include "../includes/Character.hpp"

Character::Character(void) {
    std::cout << "Character: Default constructor called" << std::endl;
    for (int i = 0; i < 4; ++i)
        _inventory[i] = 0;
}

Character::Character(const std::string& name) {
    std::cout << "Character: Name constructor called" << std::endl;
    _name = name;
    for (int i = 0; i < 4; ++i)
        _inventory[i] = 0;
}

Character::Character(const Character& rhs) {
    std::cout << "Character: Copy constructor called" << std::endl;
    *this = rhs;
}

Character::~Character(void) {
    std::cout << "Character: Destructor called" << std::endl;
    int i = 0;

    while (i < 4) {
        if (_inventory[i])
            delete _inventory[i];
        ++i;
    }
}

Character&  Character::operator=(const Character& rhs) {
    _name = rhs._name;

    int i = 0;
    while (i < 4) {
        if (_inventory[i])
            delete _inventory[i];
        equip(rhs._inventory[i]->clone());
        ++i;
    }
    return (*this);
}

const std::string& Character::getName(void) const {
    return (_name);
}

void Character::equip(AMateria* m) {
    int i = 0;

    while (_inventory[i] && i < 4)
        i++;
    if (i == 4) {
        std::cout << "Cannot equip more than 4 materias" << std::endl;
    } else {
        std::cout << "Equipping materia at " << i << " slot" << std::endl;
        _inventory[i] = m;
    }
}

void Character::unequip(int idx) {
    if (idx < 0 || idx > 3) {
        std::cout << "Invalid index, range is 0 to 3" << std::endl;
    } else if (_inventory[idx]) {
        std::cout << "Unequipping materia at " << idx << " slot" << std::endl;
        dump.push(_inventory[idx]);
        _inventory[idx] = 0;
    }
}

void Character::use(int idx, const ICharacter& target) {
    if (idx < 0 || idx > 3) {
        std::cout << "Invalid index, range is 0 to 3" << std::endl;
    } else if (!_inventory[idx]) {
        std::cout << "There's no materia in this slot" << std::endl;
    } else {
        std::cout << _name;
        _inventory[idx]->use(target);
    }
}

AMateria*  Character::getMateriaAddress(int idx) {
    if (idx < 0 || idx > 3) {
        std::cout << "Invalid index, range is 0 to 3" << std::endl;
        return (0);
    }
    return (_inventory[idx]);
}
