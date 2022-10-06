/* Copyright © 2022 Victor Nunes, Licensed under the MIT License. */

#include "../includes/WrongAnimal.hpp"

WrongAnimal::WrongAnimal(void) {
    std::cout << "WrongAnimal: Default constructor called" << std::endl;
    _type = "Tiger";
}

WrongAnimal::~WrongAnimal(void) {
    std::cout << "WrongAnimal: Destructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& src) {
    std::cout << "WrongAnimal: Copy constructor called" << std::endl;
    *this = src;
}

WrongAnimal&    WrongAnimal::operator=(const WrongAnimal& rhs) {
    std::cout << "WrongAnimal: Copy assignment operator called" << std::endl;
    _type = rhs._type;
    return (*this);
}

std::string    WrongAnimal::getType(void) const {
    return (_type);
}

void    WrongAnimal::makeSound() const {
    std::cout << _type << ": MREOWWW!" << std::endl;
}
