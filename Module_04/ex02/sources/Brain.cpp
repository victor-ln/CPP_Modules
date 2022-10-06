/* Copyright © 2022 Victor Nunes, Licensed under the MIT License. */

#include "../includes/Brain.hpp"

Brain::Brain(void) {
    std::cout << "Brain: Default constructor called" << std::endl;
    _lastIdea = 0;
}

Brain::Brain(const Brain& rhs) {
    std::cout << "Brain: Default constructor called" << std::endl;
    *this = rhs;
}

Brain::~Brain(void) {
    std::cout << "Brain: Destructor called" << std::endl;
}

Brain&  Brain::operator=(const Brain& rhs) {
    int i = 0;

    while (rhs._ideas[i].length()) {
        _ideas[i] = rhs._ideas[i];
        ++i;
    }
    while (i < 100) {
        _ideas[i].clear();
        ++i;
    }
    return (*this);
}

void Brain::showIdeas(void) const {
    for (int i = 0; _ideas[i].length(); ++i) {
        std::cout << _ideas[i] << std::endl;
    }
}

void  Brain::newIdea(const std::string& idea) {
    if (_lastIdea == 100) {
        _lastIdea = 0;
    }
    _ideas[_lastIdea] = idea;
    ++_lastIdea;
}

void  Brain::removeIdea(const size_t i) {
    if (i >= 100) {
        std::cout << "Invalid index, the range of ideas is 0 to 99\n";
        return;
    }
    _ideas[i].clear();
}
