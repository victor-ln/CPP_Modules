/* Copyright © 2022 Victor Nunes, Licensed under the MIT License. */

#include "../includes/DiamondTrap.hpp"

static void testReparing(DiamondTrap* a);
static void testTakingDamage(DiamondTrap* a);
static void testHighFive(const DiamondTrap& a);
static void testWhoAmI(const DiamondTrap& a, const DiamondTrap& b);
static void testMembers(const DiamondTrap& a, const DiamondTrap& b);

int main(void) {
    DiamondTrap a("Foo");
    std::cout << "\n";
    std::cout << "\tTesting Copy constructor:\n\n";
    DiamondTrap b(a);
    std::cout << "\n";

    testWhoAmI(a, b);
    testMembers(a, b);
    testHighFive(a);

    std::cout << "\tTesting Attack:\n\n";
    a.attack("Bar");
    std::cout << "\n";

    std::cout << "\tTesting assignment operator:\n\n";
    b = DiamondTrap("Bar");
    b.whoAmI();
    std::cout << "\n";

    testTakingDamage(&a);
    testReparing(&a);

    return (0);
}

static void    testReparing(DiamondTrap* a) {
    std::cout << "\tTesting Energy points:\n\n";
    std::cout << "Energy points: " << a->getEnergyPoints() << "\n";
    std::cout << "Hit points: " << a->getHitPoints() << "\n";
    a->beRepaired(40);
    std::cout << "Energy points: " << a->getEnergyPoints() << "\n";
    std::cout << "Hit points: " << a->getHitPoints() << "\n";
    std::cout << "\n";
}

static void    testTakingDamage(DiamondTrap* a) {
    std::cout << "\tTesting Hit Points:\n\n";
    std::cout << "Hit points: " << a->getHitPoints() << "\n";
    a->takeDamage(40);
    std::cout << "Hit points: " << a->getHitPoints() << "\n";
    std::cout << "\n";
}

static void    testMembers(const DiamondTrap& a, const DiamondTrap& b) {
    std::cout << "\tTesting Members:\n\n";
    std::cout << "a: Attack damage: " << a.getAttackDamage() << "\n";
    std::cout << "a: Hit points: " << a.getHitPoints() << "\n";
    std::cout << "a: Energy points: " << a.getEnergyPoints() << "\n";
    std::cout << "\n";
    std::cout << "b: Attack damage: " << b.getAttackDamage() << "\n";
    std::cout << "b: Hit points: " << b.getHitPoints() << "\n";
    std::cout << "b: Energy points: " << b.getEnergyPoints() << "\n";
    std::cout << "\n";
}

static void    testWhoAmI(const DiamondTrap& a, const DiamondTrap& b) {
    std::cout << "\tTesting whoAmI():\n\n";
    std::cout << "a:\n";
    a.whoAmI();
    std::cout << "\n";
    std::cout << "b:\n";
    b.whoAmI();
    std::cout << "\n";
    std::cout << "\n";
}

static void    testHighFive(const DiamondTrap& a) {
    std::cout << "\tTesting highFivesGuys():\n\n";
    a.highFivesGuys();
    std::cout << "\n";
}
