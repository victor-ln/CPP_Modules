/* Copyright © 2022 Victor Nunes, Licensed under the MIT License. */

#ifndef MODULE_04_EX01_INCLUDES_CAT_HPP_
#define MODULE_04_EX01_INCLUDES_CAT_HPP_

#include <iostream>
#include <string>

#include "./Animal.hpp"
#include "./Brain.hpp"

class Cat : public Animal {
 public:
    Cat();
    Cat(const Cat&);
    ~Cat();

    Cat& operator=(const Cat&);
    void makeSound(void) const;
    void removeIdea(const size_t);
    void showIdeas() const;
    void newIdea(const std::string&);

 private:
    Brain    *_brain;
};

#endif /* MODULE_04_EX01_INCLUDES_CAT_HPP_ */
