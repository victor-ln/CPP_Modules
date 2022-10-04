/* Copyright © 2022 Victor Nunes, Licensed under the MIT License. */

#include "../includes/AbstractAnimal.hpp"

AbstractAnimal::AbstractAnimal(void) {
    std::cout << "AbstractAnimal: Default constructor called" << std::endl;
}

AbstractAnimal::~AbstractAnimal(void) {
    std::cout << "AbstractAnimal: Destructor called" << std::endl;
}

AbstractAnimal::AbstractAnimal(const AbstractAnimal& src) {
    std::cout << "AbstractAnimal: Copy constructor called" << std::endl;
    *this = src;
}

AbstractAnimal&    AbstractAnimal::operator=(const AbstractAnimal& rhs) {
    std::cout << "AbstractAnimal: Copy assignment operator called" << std::endl;
    this->type = rhs.type;
    return (*this);
}

std::string    AbstractAnimal::getType(void) const {
    return (this->type);
}
