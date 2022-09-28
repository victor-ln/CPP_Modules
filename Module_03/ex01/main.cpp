#include "ScavTrap.hpp"

int main(void) {
	ScavTrap	a("Foo");

	a.attack("Bar");
	std::cout << "Attack damage: " << a.getAttackDamage() << std::endl;
	std::cout << "Hit points: " << a.getHitPoints() << std::endl;
	std::cout << "Energy points: " << a.getEnergyPoints() << std::endl;
	a = ScavTrap("Bar");
	ScavTrap	b(a);
	b.attack("Foo");
	std::cout << "Attack damage: " << b.getAttackDamage() << std::endl;
	std::cout << "Hit points: " << b.getHitPoints() << std::endl;
	std::cout << "Energy points: " << b.getEnergyPoints() << std::endl;
	return (0);
}
