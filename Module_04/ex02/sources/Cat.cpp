/* Copyright © 2022 Victor Nunes, Licensed under the MIT License. */

#include "../includes/Cat.hpp"

Cat::Cat(void) : AbstractAnimal() {
    std::cout << "Cat: Default constructor called" << std::endl;
    this->type = "Cat";
    this->_brain = new Brain();
}

Cat::Cat(const Cat& src) : AbstractAnimal(src) {
    std::cout << "Cat: Copy constructor called" << std::endl;
    *this = src;
}

Cat::~Cat(void) {
    std::cout << "Cat: Destructor called" << std::endl;
    delete this->_brain;
}

Cat& Cat::operator=(const Cat& rhs) {
    std::cout << "Cat: Copy assignment operator called" << std::endl;
    this->type = rhs.type;
    *this->_brain = *rhs._brain;
    return (*this);
}

void    Cat::makeSound(void) const {
    std::cout << "Cat: meooooooowwww" << std::endl;
}

void Cat::showIdeas() const {
    this->_brain->showIdeas();
}

void  Cat::newIdea(const std::string& idea) {
    this->_brain->newIdea(idea);
}

void  Cat::removeIdea(const size_t i) {
    this->_brain->removeIdea(i);
}
