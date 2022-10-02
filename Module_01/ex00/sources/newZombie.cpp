/* Copyright © 2022 Victor Nunes, Licensed under the MIT License. */

#include "../includes/Zombie.hpp"

Zombie*    newZombie(std::string name) {
    return (new Zombie(name));
}
