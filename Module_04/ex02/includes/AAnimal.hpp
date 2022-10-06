/* Copyright © 2022 Victor Nunes, Licensed under the MIT License. */

#ifndef MODULE_04_EX02_INCLUDES_AANIMAL_HPP_
#define MODULE_04_EX02_INCLUDES_AANIMAL_HPP_

#include <iostream>
#include <string>

/*
    As a guideline, when having a virtual function in a class,
    you must add a virtual destructor too (even if it does nothing).
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
