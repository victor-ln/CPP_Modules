/* Copyright © 2022 Victor Nunes, Licensed under the MIT License. */

#include "../includes/Ice.hpp"

/**
 * It calls the default constructor of the parent class, then sets the type of the
 * object to "ice"
 */
Ice::Ice(void) : AMateria("ice") {
    std::cout << "Ice: Default constructor called" << std::endl;
}

Ice::Ice(const Ice& rhs) : AMateria(rhs) {
    std::cout << "Ice: Copy constructor called" << std::endl;
    *this = rhs;
}

Ice::~Ice(void) {
    std::cout << "Ice: Destructor called" << std::endl;
}

Ice&   Ice::operator=(const AMateria& rhs) {
    std::cout << "Ice: Copy assingment operator called" << std::endl;
    (void)rhs;
    return (*this);
}

/**
 * The clone() function returns a pointer to a new Ice object that is a copy of the
 * current object.
 * 
 * @return A new instance of Ice.
 */
Ice* Ice::clone(void) const {
    return (new Ice());
}

void Ice::use(const ICharacter& target) const {
    std::cout << " shoots an ice bolt at " << target.getName() << std::endl;
}
