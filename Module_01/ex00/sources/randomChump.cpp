/* Copyright © 2022 Victor Nunes, Licensed under the MIT License. */

#include "../includes/Zombie.hpp"

void    randomChump(std::string name) {
    Zombie    newZombie(name);
    newZombie.announce();
}
