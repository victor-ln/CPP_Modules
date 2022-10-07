/* Copyright © 2022 Victor Nunes, Licensed under the MIT License. */

#include "../includes/Character.hpp"

/**
 * It initializes the _inventory array to all zeros.
 */
Character::Character(void) {
    std::cout << "Character: Default constructor called" << std::endl;
    for (int i = 0; i < 4; ++i)
        _inventory[i] = 0;
}

/**
 * It initializes the _name member variable to the value of the name parameter, and
 * initializes all of the elements of the _inventory array to 0
 * 
 * @param name The name of the character.
 */
Character::Character(const std::string& name) {
    std::cout << "Character: Name constructor called" << std::endl;
    _name = name;
    for (int i = 0; i < 4; ++i)
        _inventory[i] = 0;
}

/**
 * Copy the data from the rhs object into the current object.
 * 
 * @param rhs The right hand side of the assignment.
 */
Character::Character(const Character& rhs) {
    std::cout << "Character: Copy constructor called" << std::endl;
    for (int i = 0; i < 4; ++i)
        _inventory[i] = 0;
    *this = rhs;
}

/**
 * It deletes the objects in the inventory array
 */
Character::~Character(void) {
    std::cout << "Character: Destructor called" << std::endl;
    int i = 0;

    while (i < 4) {
        if (_inventory[i])
            delete _inventory[i];
        ++i;
    }
}

/**
 * Copy the inventory of the rhs character into the inventory of the lhs character.
 * 
 * @return A reference to the current object.
 */
Character&  Character::operator=(const Character& rhs) {
    std::cout << "Character: Copy assingment operator called" << std::endl;
    _name = rhs._name;

    int i = 0;
    while (i < 4) {
        if (_inventory[i])
            delete _inventory[i];
        if (rhs._inventory[i])
            this->_inventory[i] = rhs._inventory[i]->clone();
        ++i;
    }
    return (*this);
}

const std::string& Character::getName(void) const {
    return (_name);
}

/**
 * It loops through the inventory array and finds the first empty slot, then equips
 * the materia in that slot
 * 
 * @param m The materia to equip
 */
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

/**
 * If the index is valid, unequip the materia at that index and put it in the dump
 * 
 * @param idx the index of the materia to unequip
 */
void Character::unequip(int idx) {
    if (idx < 0 || idx > 3) {
        std::cout << "Invalid index, range is 0 to 3" << std::endl;
    } else if (_inventory[idx]) {
        std::cout << "Unequipping materia at " << idx << " slot" << std::endl;
        dump.push(_inventory[idx]);
        _inventory[idx] = 0;
    }
}

/**
 * If the index is valid, and there's a materia in the slot, then use the materia
 * on the target
 * 
 * @param idx the index of the materia in the inventory
 * @param target The target to use the materia on.
 */
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
