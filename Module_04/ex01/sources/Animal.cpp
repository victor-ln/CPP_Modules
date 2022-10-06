/* Copyright © 2022 Victor Nunes, Licensed under the MIT License. */

#include "../includes/Animal.hpp"

Animal::Animal(void) {
    std::cout << "Animal: Default constructor called" << std::endl;
    _type = "Tiger";
}

Animal::~Animal(void) {
    std::cout << "Animal: Destructor called" << std::endl;
}

Animal::Animal(const Animal& src) {
    std::cout << "Animal: Copy constructor called" << std::endl;
    *this = src;
}

Animal&    Animal::operator=(const Animal& rhs) {
    std::cout << "Animal: Copy assignment operator called" << std::endl;
    _type = rhs._type;
    return (*this);
}

std::string    Animal::getType(void) const {
    return (_type);
}

void    Animal::makeSound(void) const {
    std::cout << "Tiger: MREOWWW!" << std::endl;
}
