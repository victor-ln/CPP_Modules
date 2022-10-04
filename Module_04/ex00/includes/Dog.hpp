/* Copyright © 2022 Victor Nunes, Licensed under the MIT License. */

#ifndef MODULE_04_EX00_INCLUDES_DOG_HPP_
#define MODULE_04_EX00_INCLUDES_DOG_HPP_

#include <iostream>

#include "./Animal.hpp"

class Dog : public Animal {
 public:
    Dog(void);
    Dog(const Dog&);
    ~Dog(void);

    Dog& operator=(const Dog&);
    void makeSound(void) const;
};

#endif /* MODULE_04_EX00_INCLUDES_DOG_HPP_ */
