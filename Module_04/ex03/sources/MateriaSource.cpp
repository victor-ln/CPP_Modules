/* Copyright © 2022 Victor Nunes, Licensed under the MIT License. */

#include "../includes/MateriaSource.hpp"

MateriaSource::MateriaSource(void) {
    std::cout << "MateriaSource: Default constructor called" << std::endl;
    _lastIdx = 0;
}

MateriaSource::MateriaSource(const MateriaSource& rhs) {
    std::cout << "MateriaSource: Copy constructor called" << std::endl;
    *this = rhs;
}

MateriaSource::~MateriaSource(void) {
    std::cout << "MateriaSource: Destructor called" << std::endl;
    for (int i = 0; i < _lastIdx; ++i)
        delete _learnedMateria[i];
}

MateriaSource& MateriaSource::operator=(const MateriaSource& rhs) {
    std::cout << "MateriaSource: Copy assingment operator called" << std::endl;
    int i = 0;
    while (i < _lastIdx) {
        delete _learnedMateria[i];
        ++i;
    }
    i = 0;
    while (i < rhs._lastIdx) {
        _learnedMateria[i] = rhs._learnedMateria[i]->clone();
        ++i;
    }
    return (*this);
}

void MateriaSource::learnMateria(AMateria* newMateria) {
    if (_lastIdx == 4) {
        std::cout << "Cannot learn more materias" << std::endl;
        return;
    }
    _learnedMateria[_lastIdx] = newMateria;
    ++_lastIdx;
}

AMateria* MateriaSource::createMateria(const std::string& type) {
    if (!_lastIdx) {
        std::cout << "Cannot create materia, no elements learned yet"
                << std::endl;
        return (0);
    }
    int i = 0;
    while (i < _lastIdx) {
        if (_learnedMateria[i]->getType() == type)
            return (_learnedMateria[i]->clone());
        ++i;
    }
    std::cout << "Cannot create materia, unknown element" << std::endl;
    return (0);
}
