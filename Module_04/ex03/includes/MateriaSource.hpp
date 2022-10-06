/* Copyright © 2022 Victor Nunes, Licensed under the MIT License. */

#ifndef MODULE_04_EX03_INCLUDES_MATERIASOURCE_HPP_
#define MODULE_04_EX03_INCLUDES_MATERIASOURCE_HPP_

#include <iostream>
#include <string>

#include "./AMateria.hpp"
#include "./IMateriaSource.hpp"

class MateriaSource : public IMateriaSource {
 public:
    MateriaSource(void);
    MateriaSource(const MateriaSource&);
    ~MateriaSource(void);

    MateriaSource& operator=(const MateriaSource&);
    void learnMateria(AMateria*);
    AMateria* createMateria(const std::string& type);

 private:
    AMateria    *_learnedMateria[4];
    int         _lastIdx;
};

#endif /* MODULE_04_EX03_INCLUDES_MATERIASOURCE_HPP_ */
