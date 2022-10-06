/* Copyright © 2022 Victor Nunes, Licensed under the MIT License. */

#include "../includes/Ice.hpp"

Ice::Ice(void) : AMateria() {
    std::cout << "Ice: Default constructor called" << std::endl;
    _type = std::string("ice");
}

Ice::Ice(const std::string& type) : AMateria(type) {
    std::cout << "Ice: Copy constructor called" << std::endl;
    _type = std::string("cure");
}

Ice::Ice(const AMateria& rhs) : AMateria(rhs) {
    std::cout << "Ice: Copy constructor called" << std::endl;
    *this = rhs;
}

Ice::~Ice(void) {
    std::cout << "Ice: Destructor called" << std::endl;
}

Ice&   Ice::operator=(const AMateria& rhs) {
    (void)rhs;
    return (*this);
}

Ice* Ice::clone(void) const {
    return (new Ice());
}

void Ice::use(const ICharacter& target) const {
    std::cout << " shoots an ice bolt at " << target.getName() << std::endl;
}
