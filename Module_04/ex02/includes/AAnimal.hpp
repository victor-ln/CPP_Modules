/* Copyright © 2022 Victor Nunes, Licensed under the MIT License. */

#ifndef MODULE_04_EX02_INCLUDES_AANIMAL_HPP_
#define MODULE_04_EX02_INCLUDES_AANIMAL_HPP_

#include <iostream>
#include <string>

/**
 * 
 * Virtual functions:
 * 
 * A virtual member function will be called a method.
 * A method is a member function whose resolution will be dynamic.
*/

/**
 * 
 * Virtual destructor:
 * 
 * Making base class destructor virtual guarantees 
 * that the object of derived class is destructed properly.
 * As a guideline, when having a virtual function in a class,
 * you must add a virtual destructor too (even if it does nothing).
*/

/**
 * 
 * Pure Virtual functions:
 * 
 * Sometimes implementation of all function cannot be provided
 * in a base class because we don’t know the implementation.
 * Such a class is called abstract class.
 * A pure virtual function is a function we define equaling zero, which means 
 * that there's no implementation for it and therefore we cannot instantiate its
 * class, we must override that function in a derived class, 
 * otherwise the derived class will also become abstract class.
*/

/**
 * 
 * Abstract class:
 * 
 * A class is abstract if it has at least one pure virtual function.
 * Conventionally, we mark an 'A' prefix preceding an abstract class name.
*/

class AAnimal {
 public:
    AAnimal();
    AAnimal(const AAnimal&);
    virtual ~AAnimal(void);

    AAnimal&        operator=(const AAnimal&);

    std::string     getType(void) const;
    virtual void    makeSound(void) const = 0;

 protected:
    std::string _type;
};

#endif /* MODULE_04_EX02_INCLUDES_AANIMAL_HPP_ */
