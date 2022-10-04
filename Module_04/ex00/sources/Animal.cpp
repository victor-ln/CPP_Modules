/* Copyright © 2022 Victor Nunes, Licensed under the MIT License. */

#include "../includes/Animal.hpp"

Animal::Animal(void) {
    std::cout << "Animal: Default constructor called" << std::endl;
    this->type = "Tiger";
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
    this->type = rhs.type;
    return (*this);
}

std::string    Animal::getType(void) const {
    return (this->type);
}

void    Animal::makeSound() const {
    std::cout << "Tiger: MREOWWW!" << std::endl;
}
