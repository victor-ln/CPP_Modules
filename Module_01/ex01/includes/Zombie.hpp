/* Copyright © 2022 Victor Nunes, Licensed under the MIT License. */

#ifndef MODULE_01_EX01_INCLUDES_ZOMBIE_HPP_
#define MODULE_01_EX01_INCLUDES_ZOMBIE_HPP_

#include <iostream>
#include <string>

class Zombie {
 public:
    Zombie(void);
    ~Zombie();
    explicit Zombie(std::string);

    void    announce(void);

 private:
    std::string        _name;
};

Zombie*    zombieHorde(int N, std::string name);

#endif /* MODULE_01_EX01_INCLUDES_ZOMBIE_HPP_ */
