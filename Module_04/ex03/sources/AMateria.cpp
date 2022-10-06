/* Copyright © 2022 Victor Nunes, Licensed under the MIT License. */

#include "../includes/AMateria.hpp"

AMateria::AMateria(const std::string& type) {
    std::cout << "AMateria: string constructor called" << std::endl;
    _type = type;
}

AMateria::AMateria(void) : _type("aMateria") {
    std::cout << "AMateria: Default constructor called" << std::endl;
}

AMateria::AMateria(const AMateria& rhs) {
    std::cout << "AMateria: Copy constructor called" << std::endl;
    *this = rhs;
}

AMateria::~AMateria(void) {
    std::cout << "AMateria: Destructor called" << std::endl;
}

AMateria& AMateria::operator=(const AMateria& rhs) {
    (void)rhs;
    return (*this);
}

const std::string& AMateria::getType(void) const {
    return (_type);
}

void AMateria::use(const ICharacter& target) const {
    std::cout << " hits " << target.getName() << std::endl;
}
