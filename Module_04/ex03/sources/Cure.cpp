/* Copyright © 2022 Victor Nunes, Licensed under the MIT License. */

#include "../includes/Cure.hpp"

/**
 * Cure's default constructor calls AMateria's default constructor, then sets
 * Cure's type to "cure"
 */
Cure::Cure(void) : AMateria("cure") {
    std::cout << "Cure: Default constructor called" << std::endl;
}

Cure::Cure(const Cure& rhs) : AMateria(rhs) {
    std::cout << "Cure: Copy constructor called" << std::endl;
    *this = rhs;
}

Cure::~Cure(void) {
    std::cout << "Cure: Destructor called" << std::endl;
}

Cure&   Cure::operator=(const Cure& rhs) {
    std::cout << "Cure: Copy assingment operator called" << std::endl;
    (void)rhs;
    return (*this);
}

/**
 * Clone() returns a pointer to a new Cure object, which is a copy of the Cure
 * object that called the function.
 * 
 * @return A pointer to a new Cure object.
 */
Cure* Cure::clone() const {
    return (new Cure());
}

void Cure::use(const ICharacter& target) const {
    std::cout << " heals " << target.getName() << "’s wounds " << std::endl;
}
