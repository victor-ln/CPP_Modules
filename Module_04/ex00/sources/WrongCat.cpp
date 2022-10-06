/* Copyright © 2022 Victor Nunes, Licensed under the MIT License. */

#include "../includes/WrongCat.hpp"

WrongCat::WrongCat(void) : WrongAnimal() {
    std::cout << "WrongCat: Default constructor called" << std::endl;
    _type = "WrongCat";
}

WrongCat::WrongCat(const WrongCat& src) : WrongAnimal(src) {
    std::cout << "WrongCat: Copy constructor called" << std::endl;
    *this = src;
}

WrongCat::~WrongCat(void) {
    std::cout << "WrongCat: Destructor called" << std::endl;
}

WrongCat& WrongCat::operator=(const WrongCat& rhs) {
    std::cout << "WrongCat: Copy assignment operator called" << std::endl;
    _type = rhs._type;
    return (*this);
}

void    WrongCat::makeSound(void) const {
    std::cout << _type << ": meooooooowwww" << std::endl;
}
