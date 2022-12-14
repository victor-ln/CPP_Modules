/* Copyright © 2022 Victor Nunes, Licensed under the MIT License. */

#include "../includes/Zombie.hpp"

int main(void) {
    Zombie    *zombieAllocated;
    Zombie    zombieStack(std::string("Foo"));

    zombieStack.announce();
    zombieAllocated = newZombie(std::string("FooBar"));
    zombieAllocated->announce();
    randomChump(std::string("Bar"));
    delete zombieAllocated;
    return (0);
}
