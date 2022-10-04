/* Copyright © 2022 Victor Nunes, Licensed under the MIT License. */

#include "../includes/Dog.hpp"

Dog::Dog(void) : AbstractAnimal() {
    std::cout << "Dog: Default constructor called" << std::endl;
    this->type = "Dog";
    this->_brain = new Brain();
}

Dog::Dog(const Dog& src) : AbstractAnimal(src) {
    std::cout << "Dog: Copy constructor called" << std::endl;
    *this = src;
}

Dog::~Dog(void) {
    std::cout << "Dog: Destructor called" << std::endl;
    delete this->_brain;
}

Dog& Dog::operator=(const Dog& rhs) {
    std::cout << "Dog: Copy assignment operator called" << std::endl;
    this->type = rhs.type;
    *this->_brain = *rhs._brain;
    return (*this);
}

void    Dog::makeSound(void) const {
    std::cout << "Dog: Ruff! Ruff! ARRRRfffff" << std::endl;
}

void Dog::showIdeas() const {
    this->_brain->showIdeas();
}

void  Dog::newIdea(const std::string& idea) {
    this->_brain->newIdea(idea);
}

void  Dog::removeIdea(const size_t i) {
    this->_brain->removeIdea(i);
}
