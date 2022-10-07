/* Copyright © 2022 Victor Nunes, Licensed under the MIT License. */

#include "../includes/Cat.hpp"

/**
 * The default constructor for the Cat class is called. It calls the default
 * constructor for the Animal class, and then sets the _type variable to "Cat"
 */
Cat::Cat(void) : Animal() {
    std::cout << "Cat: Default constructor called" << std::endl;
    _type = "Cat";
}

/**
 * The copy constructor is called when a new object is created from an existing
 * object, as a copy of the existing object
 * 
 * @param src The object being copied.
 */
Cat::Cat(const Cat& src) : Animal(src) {
    std::cout << "Cat: Copy constructor called" << std::endl;
    *this = src;
}

/**
 * The destructor is called when the object is destroyed
 */
Cat::~Cat(void) {
    std::cout << "Cat: Destructor called" << std::endl;
}

Cat& Cat::operator=(const Cat& rhs) {
    std::cout << "Cat: Copy assignment operator called" << std::endl;
    _type = rhs._type;
    return (*this);
}

void    Cat::makeSound(void) const {
    std::cout << _type << ": meooooooowwww" << std::endl;
}
