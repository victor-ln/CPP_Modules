/* Copyright © 2022 Victor Nunes, Licensed under the MIT License. */

#include "../includes/ScavTrap.hpp"

int main(void) {
    ScavTrap    a("Foo");

    a.attack("Bar");
    a = ScavTrap("Bar");
    ScavTrap    b(a);
    std::cout << "Attack damage: " << b.getAttackDamage() << std::endl;
    std::cout << "Hit points: " << b.getHitPoints() << std::endl;
    std::cout << "Energy points: " << b.getEnergyPoints() << std::endl;
    b.attack("Foo");
    b.takeDamage(20);
    std::cout << "Attack damage: " << b.getAttackDamage() << std::endl;
    std::cout << "Hit points: " << b.getHitPoints() << std::endl;
    std::cout << "Energy points: " << b.getEnergyPoints() << std::endl;
    a.guardGate();
    return (0);
}
