/* Copyright © 2022 Victor Nunes, Licensed under the MIT License. */

#include "../includes/Dog.hpp"

Dog::Dog(void) : Animal() {
    std::cout << "Dog: Default constructor called" << std::endl;
    _type = "Dog";
}

Dog::Dog(const Dog& src) : Animal(src) {
    std::cout << "Dog: Copy constructor called" << std::endl;
    *this = src;
}

Dog::~Dog(void) {
    std::cout << "Dog: Destructor called" << std::endl;
}

Dog& Dog::operator=(const Dog& rhs) {
    std::cout << "Dog: Copy assignment operator called" << std::endl;
    _type = rhs._type;
    return (*this);
}

void    Dog::makeSound(void) const {
    std::cout << "Dog: Ruff! Ruff! ARRRRfffff" << std::endl;
}
