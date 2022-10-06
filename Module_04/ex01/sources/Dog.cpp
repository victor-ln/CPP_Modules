/* Copyright © 2022 Victor Nunes, Licensed under the MIT License. */

#include "../includes/Dog.hpp"

Dog::Dog(void) : Animal() {
    std::cout << "Dog: Default constructor called" << std::endl;
    _type = "Dog";
    _brain = new Brain();
}

Dog::Dog(const Dog& src) : Animal(src) {
    std::cout << "Dog: Copy constructor called" << std::endl;
    *this = src;
}

Dog::~Dog(void) {
    std::cout << "Dog: Destructor called" << std::endl;
    delete _brain;
}

Dog& Dog::operator=(const Dog& rhs) {
    std::cout << "Dog: Copy assignment operator called" << std::endl;
    _type = rhs._type;
    *_brain = *rhs._brain;
    return (*this);
}

void    Dog::makeSound(void) const {
    std::cout << _type << ": Ruff! Ruff! ARRRRfffff" << std::endl;
}

void Dog::showIdeas(void) const {
    _brain->showIdeas();
}

void  Dog::newIdea(const std::string& idea) {
    _brain->newIdea(idea);
}

void  Dog::removeIdea(const size_t i) {
    _brain->removeIdea(i);
}
