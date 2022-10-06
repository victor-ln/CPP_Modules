/* Copyright © 2022 Victor Nunes, Licensed under the MIT License. */

#ifndef MODULE_04_EX01_INCLUDES_DOG_HPP_
#define MODULE_04_EX01_INCLUDES_DOG_HPP_

#include <iostream>
#include <string>

#include "./Animal.hpp"
#include "./Brain.hpp"

class Dog : public Animal {
 public:
    Dog(void);
    Dog(const Dog&);
    ~Dog(void);

    Dog& operator=(const Dog&);
    void makeSound(void) const;
    void removeIdea(const size_t);
    void showIdeas(void) const;
    void newIdea(const std::string&);

 private:
    Brain    *_brain;
};

#endif /* MODULE_04_EX01_INCLUDES_DOG_HPP_ */
