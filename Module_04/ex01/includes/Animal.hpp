/* Copyright © 2022 Victor Nunes, Licensed under the MIT License. */

#ifndef MODULE_04_EX01_INCLUDES_ANIMAL_HPP_
#define MODULE_04_EX01_INCLUDES_ANIMAL_HPP_

#include <iostream>
#include <string>

/**
 * 
 * Virtual functions:
 * 
 * A virtual member function will be called a method.
 * A method is a member function whose resolution will be dynamic.
 * 
*/

/**
 * 
 * Virtual destructor:
 * 
 * Making base class destructor virtual guarantees 
 * that the object of derived class is destructed properly.
 * As a guideline, when having a virtual function in a class,
 * you must add a virtual destructor too (even if it does nothing).
 * 
*/

class Animal {
 public:
    Animal(void);
    Animal(const Animal&);
    virtual ~Animal(void);

    Animal&            operator=(const Animal&);

    const std::string& getType(void) const;
    virtual void       makeSound(void) const;

 protected:
    std::string _type;
};

#endif /* MODULE_04_EX01_INCLUDES_ANIMAL_HPP_ */
