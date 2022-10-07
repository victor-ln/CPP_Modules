/* Copyright © 2022 Victor Nunes, Licensed under the MIT License. */

#include "../includes/Dog.hpp"

Dog::Dog(void) : Animal() {
    std::cout << "Dog: Default constructor called" << std::endl;
    _type = "Dog";
    _brain = new Brain();
}

Dog::Dog(const Dog& src) : Animal(src) {
    std::cout << "Dog: Copy constructor called" << std::endl;
    _brain = new Brain();
    *this = src;
}

Dog::~Dog(void) {
    std::cout << "Dog: Destructor called" << std::endl;
    delete _brain;
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
Dog& Dog::operator=(const Dog& rhs) {
    std::cout << "Dog: Copy assignment operator called" << std::endl;
    _type = rhs._type;
    *_brain = *rhs._brain;
    return (*this);
}

void    Dog::makeSound(void) const {
    std::cout << _type << ": Ruff! Ruff! ARRRRfffff" << std::endl;
}

/**
 * The showIdeas() function of the Dog class calls the showIdeas() function of the
 * Brain class.
 */
void Dog::showIdeas(void) const {
    _brain->showIdeas();
}

/**
 * The Dog class has a newIdea function that takes a string and calls the Brain
 * class's newIdea function with that string.
 * 
 * @param idea The idea to add to the brain.
 */
void  Dog::newIdea(const std::string& idea) {
    _brain->newIdea(idea);
}

/**
 * It removes the idea at index i from the cat's brain
 * 
 * @param i the index of the idea to remove
 */
void  Dog::removeIdea(const size_t i) {
    _brain->removeIdea(i);
}
