/* Copyright © 2022 Victor Nunes, Licensed under the MIT License. */

#include "../includes/Cure.hpp"

Cure::Cure(void) : AMateria() {
    std::cout << "Cure: Default constructor called" << std::endl;
    _type = std::string("cure");
}

Cure::Cure(const std::string& type) : AMateria(type) {
    std::cout << "Cure: Copy constructor called" << std::endl;
    _type = std::string("cure");
}

Cure::Cure(const AMateria& rhs) : AMateria(rhs) {
    std::cout << "Cure: Copy constructor called" << std::endl;
    *this = rhs;
}

Cure::~Cure(void) {
    std::cout << "Cure: Destructor called" << std::endl;
}

Cure&   Cure::operator=(const Cure& rhs) {
    (void)rhs;
    return (*this);
}

Cure* Cure::clone() const {
    return (new Cure());
}

void Cure::use(const ICharacter& target) const {
    std::cout << " heals " << target.getName() << "’s wounds " << std::endl;
}
