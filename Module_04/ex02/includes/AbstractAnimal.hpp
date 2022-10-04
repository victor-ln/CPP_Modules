/* Copyright © 2022 Victor Nunes, Licensed under the MIT License. */

#ifndef MODULE_04_EX02_INCLUDES_ABSTRACTANIMAL_HPP_
#define MODULE_04_EX02_INCLUDES_ABSTRACTANIMAL_HPP_

#include <iostream>
#include <string>

/*
    As a guideline, when having a virtual function in a class,
    you must add a virtual destructor too (even if it does nothing).
*/

class AbstractAnimal {
 public:
    AbstractAnimal();
    AbstractAnimal(const AbstractAnimal&);
    virtual ~AbstractAnimal(void);

    AbstractAnimal&         operator=(const AbstractAnimal&);

    std::string     getType(void) const;
    virtual void    makeSound(void) const = 0;

 protected:
    std::string type;
};

#endif /* MODULE_04_EX02_INCLUDES_ABSTRACTANIMAL_HPP_ */
