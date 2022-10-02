/* Copyright © 2022 Victor Nunes, Licensed under the MIT License. */

#include <cstdlib>

#include "../includes/Zombie.hpp"

int    main(void) {
    Zombie*            zombies;
    std::string        zombieName;
    std::string        zombieQt;
    int                numberOfZombies = 0;

    std::cout << "Enter the zombie name: " << std::endl;
    while (zombieName.empty() && !std::cin.eof()) {
        std::cin.clear();
        std::getline(std::cin, zombieName);
    }
    if (std::cin.eof())
        zombieName = "Foo";
    std::cout << "Enter the number of Zombies: " << std::endl;
    std::getline(std::cin, zombieQt);
    if (!std::cin.eof())
        numberOfZombies = atoi(zombieQt.c_str());
    zombies = zombieHorde(numberOfZombies, zombieName);
    if (zombies == NULL)
        return (1);
    for (int i = 0; i < numberOfZombies; i++)
        zombies[i].announce();
    delete [] zombies;
    return (0);
}
