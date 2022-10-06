/* Copyright © 2022 Victor Nunes, Licensed under the MIT License. */

#ifndef MODULE_04_EX00_INCLUDES_ANIMAL_HPP_
#define MODULE_04_EX00_INCLUDES_ANIMAL_HPP_

#include <iostream>
#include <string>

/*
    As a guideline, when having a virtual function in a class,
    you must add a virtual destructor too (even if it does nothing).
*/

class Animal {
 public:
    Animal(void);
    Animal(const Animal&);
    virtual ~Animal(void);

    Animal&            operator=(const Animal&);

    std::string        getType(void) const;
    virtual void       makeSound(void) const;

 protected:
    std::string _type;
};

#endif /* MODULE_04_EX00_INCLUDES_ANIMAL_HPP_ */
