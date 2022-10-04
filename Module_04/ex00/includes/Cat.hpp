/* Copyright © 2022 Victor Nunes, Licensed under the MIT License. */

#ifndef MODULE_04_EX00_INCLUDES_CAT_HPP_
#define MODULE_04_EX00_INCLUDES_CAT_HPP_

#include <iostream>

#include "./Animal.hpp"

class Cat : public Animal {
 public:
    Cat(void);
    Cat(const Cat&);
    ~Cat(void);

    Cat& operator=(const Cat&);
    void makeSound(void) const;
};

#endif /* MODULE_04_EX00_INCLUDES_CAT_HPP_ */
