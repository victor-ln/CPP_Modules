/* Copyright © 2022 Victor Nunes, Licensed under the MIT License. */

#include "../includes/Cat.hpp"

Cat::Cat(void) : Animal() {
    std::cout << "Cat: Default constructor called" << std::endl;
    _type = "Cat";
}

Cat::Cat(const Cat& src) : Animal(src) {
    std::cout << "Cat: Copy constructor called" << std::endl;
    *this = src;
}

Cat::~Cat(void) {
    std::cout << "Cat: Destructor called" << std::endl;
}

Cat& Cat::operator=(const Cat& rhs) {
    std::cout << "Cat: Copy assignment operator called" << std::endl;
    _type = rhs._type;
    return (*this);
}

void    Cat::makeSound(void) const {
    std::cout << "Cat: meooooooowwww" << std::endl;
}
