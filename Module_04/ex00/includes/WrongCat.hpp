/* Copyright © 2022 Victor Nunes, Licensed under the MIT License. */

#ifndef MODULE_04_EX00_INCLUDES_WRONGCAT_HPP_
#define MODULE_04_EX00_INCLUDES_WRONGCAT_HPP_

#include <iostream>

#include "./WrongAnimal.hpp"

class WrongCat : public WrongAnimal {
 public:
    WrongCat(void);
    WrongCat(const WrongCat&);
    ~WrongCat(void);

    WrongCat& operator=(const WrongCat&);
    void makeSound(void) const;
};

#endif /* MODULE_04_EX00_INCLUDES_WRONGCAT_HPP_ */
