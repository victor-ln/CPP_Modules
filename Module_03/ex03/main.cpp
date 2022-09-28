#include "DiamondTrap.hpp"

int main(void) {
	DiamondTrap a("Foo");
	DiamondTrap b(a);

	a.attack("Bar");
	a.whoAmI();
	b.whoAmI();
	b = DiamondTrap("Bar");
	b.attack("Foo");
	b.whoAmI();
	std::cout << "Attack damage: " << a.getAttackDamage() << std::endl;
	std::cout << "Hit points: " << a.getHitPoints() << std::endl;
	a.highFivesGuys();
	std::cout << "Energy points: " << a.getEnergyPoints() << std::endl;
	a.takeDamage(40);
	std::cout << "Hit points: " << a.getHitPoints() << std::endl;
	return (0);
}
