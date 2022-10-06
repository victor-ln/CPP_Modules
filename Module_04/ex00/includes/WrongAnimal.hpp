/* Copyright © 2022 Victor Nunes, Licensed under the MIT License. */

#ifndef MODULE_04_EX00_INCLUDES_WRONGANIMAL_HPP_
#define MODULE_04_EX00_INCLUDES_WRONGANIMAL_HPP_

#include <iostream>
#include <string>

class WrongAnimal {
 public:
    WrongAnimal(void);
    WrongAnimal(const WrongAnimal&);
    ~WrongAnimal(void);

    WrongAnimal&            operator=(const WrongAnimal&);

    std::string        getType(void) const;
    void       makeSound(void) const;

 protected:
    std::string _type;
};

#endif /* MODULE_04_EX00_INCLUDES_WRONGANIMAL_HPP_ */
