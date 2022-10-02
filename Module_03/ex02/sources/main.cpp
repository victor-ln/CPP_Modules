/* Copyright © 2022 Victor Nunes, Licensed under the MIT License. */

#include "../includes/FragTrap.hpp"

int main(void) {
    FragTrap    a("Foo");

    std::cout << "Hit points: " << a.getHitPoints() << std::endl;
    std::cout << "Energy points: " << a.getEnergyPoints() << std::endl;
    a.attack("Bar");
    std::cout << "Attack damage: " << a.getAttackDamage() << std::endl;
    std::cout << "Hit points: " << a.getHitPoints() << std::endl;
    std::cout << "Energy points: " << a.getEnergyPoints() << std::endl;
    a = FragTrap("Bar");
    FragTrap    b(a);
    std::cout << "Hit points: " << b.getHitPoints() << std::endl;
    std::cout << "Energy points: " << b.getEnergyPoints() << std::endl;
    b.attack("Foo");
    std::cout << "Attack damage: " << b.getAttackDamage() << std::endl;
    std::cout << "Hit points: " << b.getHitPoints() << std::endl;
    std::cout << "Energy points: " << b.getEnergyPoints() << std::endl;
    b.highFivesGuys();
    return (0);
}
