/* Copyright © 2022 Victor Nunes, Licensed under the MIT License. */

#ifndef MODULE_04_EX03_INCLUDES_IMATERIASOURCE_HPP_
#define MODULE_04_EX03_INCLUDES_IMATERIASOURCE_HPP_

#include <string>

#include "./AMateria.hpp"

/**
 * 
 * Interface:
 * 
 * Interfaces work similarly to abstract classes, they also cannot be
 * instantiated, the difference is that interfaces cannot have attributes,
 * they are just a way to define all implementations (pure methods).
 * Conventionally, we mark an 'I' prefix preceding an interface name.
 * 
*/

class IMateriaSource {
 public:
    virtual ~IMateriaSource(void) {}
    virtual void learnMateria(AMateria*) = 0;
    virtual AMateria* createMateria(const std::string& type) = 0;
};

#endif /* MODULE_04_EX03_INCLUDES_IMATERIASOURCE_HPP_ */
