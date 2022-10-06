/* Copyright © 2022 Victor Nunes, Licensed under the MIT License. */

#ifndef MODULE_04_EX02_INCLUDES_CAT_HPP_
#define MODULE_04_EX02_INCLUDES_CAT_HPP_

#include <iostream>
#include <string>

#include "./AAnimal.hpp"
#include "./Brain.hpp"

class Cat : public AAnimal {
 public:
    Cat(void);
    Cat(const Cat&);
    ~Cat(void);

    Cat& operator=(const Cat&);
    void makeSound(void) const;
    void removeIdea(const size_t);
    void showIdeas(void) const;
    void newIdea(const std::string&);

 private:
    Brain    *_brain;
};

#endif /* MODULE_04_EX02_INCLUDES_CAT_HPP_ */
