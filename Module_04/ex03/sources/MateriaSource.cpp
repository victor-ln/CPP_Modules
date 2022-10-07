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

/**
 * It deletes all the materia that were stored in the array
 */
MateriaSource::~MateriaSource(void) {
    std::cout << "MateriaSource: Destructor called" << std::endl;
    for (int i = 0; i < _lastIdx; ++i)
        delete _learnedMateria[i];
}

/**
 * It deletes all the materia in the current object, then copies all the materia
 * from the rhs object into the current object
 * 
 * @return A reference to the current object.
 */
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

/**
 * If the last index is equal to 4, we can't learn more materias, so we print an
 * error message and return. Otherwise, we set the learned materia at the last
 * index to the new materia, and increment the last index
 * 
 * @param newMateria a pointer to the materia to be learned.
 */
void MateriaSource::learnMateria(AMateria* newMateria) {
    if (_lastIdx == 4) {
        std::cout << "Cannot learn more materias" << std::endl;
        return;
    }
    _learnedMateria[_lastIdx] = newMateria;
    ++_lastIdx;
}

/**
 * It creates a new materia
 * of the given type, if it exists in the source
 * 
 * @param type the type of the materia to create.
 * 
 * @return A pointer to a new instance of the materia.
 */
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
