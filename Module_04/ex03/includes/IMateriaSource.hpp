/* Copyright © 2022 Victor Nunes, Licensed under the MIT License. */

#ifndef MODULE_04_EX03_INCLUDES_IMATERIASOURCE_HPP_
#define MODULE_04_EX03_INCLUDES_IMATERIASOURCE_HPP_

#include <string>

#include "./AMateria.hpp"

class IMateriaSource {
 public:
    virtual ~IMateriaSource(void) {}
    virtual void learnMateria(AMateria*) = 0;
    virtual AMateria* createMateria(const std::string& type) = 0;
};

#endif /* MODULE_04_EX03_INCLUDES_IMATERIASOURCE_HPP_ */
