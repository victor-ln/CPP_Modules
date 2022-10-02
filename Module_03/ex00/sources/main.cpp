/* Copyright © 2022 Victor Nunes, Licensed under the MIT License. */

#include "../includes/ClapTrap.hpp"

int main(void) {
    ClapTrap    a("Foo");

    std::cout << "Attack damage: " << a.getAttackDamage() << std::endl;
    std::cout << "Hit points: " << a.getHitPoints() << std::endl;
    std::cout << "Energy points: " << a.getEnergyPoints() << std::endl;
    a.attack("Bar");
    std::cout << "Hit points: " << a.getHitPoints() << std::endl;
    std::cout << "Energy points: " << a.getEnergyPoints() << std::endl;
    for (int i = 0; i < 11; i++) {
        a.takeDamage(5);
        a.beRepaired(5);
        std::cout << "Hit points: " << a.getHitPoints() << std::endl;
        std::cout << "Energy points: " << a.getEnergyPoints() << std::endl;
    }
    a.attack("Bar");
    return (0);
}
