/* Copyright © 2022 Victor Nunes, Licensed under the MIT License. */

#include "../includes/Brain.hpp"

Brain::Brain(void) {
    std::cout << "Brain: Default constructor called" << std::endl;
    this->_lastIdea = 0;
}

Brain::Brain(const Brain& rhs) {
    std::cout << "Brain: Default constructor called" << std::endl;
    *this = rhs;
}

Brain::~Brain() {
    std::cout << "Brain: Destructor called" << std::endl;
}

Brain&  Brain::operator=(const Brain& rhs) {
    for (int i = 0; rhs._ideas[i].length(); ++i) {
        this->_ideas[i] = rhs._ideas[i];
    }
    return (*this);
}

void Brain::showIdeas() const {
    for (int i = 0; this->_ideas[i].length(); ++i) {
        std::cout << this->_ideas[i] << std::endl;
    }
}

void  Brain::newIdea(const std::string& idea) {
    if (this->_lastIdea == 100) {
        this->_lastIdea = 0;
    }
    this->_ideas[this->_lastIdea] = idea;
    ++this->_lastIdea;
}

void  Brain::removeIdea(const size_t i) {
    if (i >= 100) {
        std::cout << "Invalid index, the range of ideas is 0 to 99\n";
        return;
    }
    this->_ideas[i].clear();
}
