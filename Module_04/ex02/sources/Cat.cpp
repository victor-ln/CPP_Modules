/* Copyright © 2022 Victor Nunes, Licensed under the MIT License. */

#include "../includes/Cat.hpp"

Cat::Cat(void) : AAnimal() {
    std::cout << "Cat: Default constructor called" << std::endl;
    _type = "Cat";
    _brain = new Brain();
}

Cat::Cat(const Cat& src) : AAnimal(src) {
    std::cout << "Cat: Copy constructor called" << std::endl;
    _brain = new Brain();
    *this = src;
}

Cat::~Cat(void) {
    std::cout << "Cat: Destructor called" << std::endl;
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
Cat& Cat::operator=(const Cat& rhs) {
    std::cout << "Cat: Copy assignment operator called" << std::endl;
    _type = rhs._type;
    *_brain = *rhs._brain;
    return (*this);
}

void    Cat::makeSound(void) const {
    std::cout << _type << ": meooooooowwww" << std::endl;
}

/**
 * The showIdeas() function of the Cat class calls the showIdeas() function of the
 * Brain class.
 */
void Cat::showIdeas(void) const {
    _brain->showIdeas();
}

/**
 * The Cat class has a newIdea function that takes a string and calls the Brain
 * class's newIdea function with that string.
 * 
 * @param idea The idea to add to the brain.
 */
void  Cat::newIdea(const std::string& idea) {
    _brain->newIdea(idea);
}

/**
 * It removes the idea at index i from the cat's brain
 * 
 * @param i the index of the idea to remove
 */
void  Cat::removeIdea(const size_t i) {
    _brain->removeIdea(i);
}
