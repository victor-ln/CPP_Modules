#include "HumanB.hpp"

HumanB::HumanB(std::string name) {
	this->_name = name;
}

HumanB::~HumanB() {
	return ;
}

void	HumanB::attack(void) const {
	std::cout << this->_name << "attacks with their " << this->_weapon->getType() << std::endl;
}

void	HumanB::setWeapon(Weapon& newWeapon) {
	this->_weapon = &newWeapon;
}
