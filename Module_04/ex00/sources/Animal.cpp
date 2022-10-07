/* Copyright © 2022 Victor Nunes, Licensed under the MIT License. */

#include "../includes/Animal.hpp"

/**
 * The default constructor for the Animal class is called.
 * It sets the _type variable to "Tiger".
 */
Animal::Animal(void) {
    std::cout << "Animal: Default constructor called" << std::endl;
    _type = "Tiger";
}

/**
 * The destructor is called when an object is destroyed
 */
Animal::~Animal(void) {
    std::cout << "Animal: Destructor called" << std::endl;
}

/**
 * The copy constructor is called when an object is initialized with another object
 * of the same type.
 * 
 * @param src The object that is being copied.
 */
Animal::Animal(const Animal& src) {
    std::cout << "Animal: Copy constructor called" << std::endl;
    *this = src;
}

/**
 * "Copy the rhs object into the current object, and return a reference to the
 * current object."
 * 
 * The first thing we do is print out a message to the console. This is just to
 * show that the function is being called
 * 
 * @return A reference to the object that called the function.
 */
Animal&    Animal::operator=(const Animal& rhs) {
    std::cout << "Animal: Copy assignment operator called" << std::endl;
    _type = rhs._type;
    return (*this);
}

/**
 * It returns the type of the animal.
 * 
 * @return A reference to the private member variable _type.
 */
const std::string&    Animal::getType(void) const {
    return (_type);
}

/**
 * MakeSound() is a public member function of the Animal class that takes no
 * arguments and returns nothing. It prints the type of the animal and the sound it
 * makes.
 */
void    Animal::makeSound(void) const {
    std::cout << _type << ": MREOWWW!" << std::endl;
}
