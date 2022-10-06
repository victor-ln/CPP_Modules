/* Copyright © 2022 Victor Nunes, Licensed under the MIT License. */

#include "../includes/AAnimal.hpp"

AAnimal::AAnimal(void) {
    std::cout << "AAnimal: Default constructor called" << std::endl;
}

AAnimal::~AAnimal(void) {
    std::cout << "AAnimal: Destructor called" << std::endl;
}

AAnimal::AAnimal(const AAnimal& src) {
    std::cout << "AAnimal: Copy constructor called" << std::endl;
    *this = src;
}

AAnimal&    AAnimal::operator=(const AAnimal& rhs) {
    std::cout << "AAnimal: Copy assignment operator called" << std::endl;
    _type = rhs._type;
    return (*this);
}

std::string    AAnimal::getType(void) const {
    return (_type);
}
