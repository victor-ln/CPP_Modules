/* Copyright © 2022 Victor Nunes, Licensed under the MIT License. */

#ifndef MODULE_01_EX00_INCLUDES_ZOMBIE_HPP_
#define MODULE_01_EX00_INCLUDES_ZOMBIE_HPP_

#include <iostream>
#include <string>

class Zombie {
 public:
    explicit Zombie(std::string);
    ~Zombie();

    void    announce(void);

 private:
    std::string        _name;
};

void        randomChump(std::string name);
Zombie*     newZombie(std::string name);

#endif /* MODULE_01_EX00_INCLUDES_ZOMBIE_HPP_ */
