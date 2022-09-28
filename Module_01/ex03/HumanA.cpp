#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon& type) {
	this->_name = name;
	this->_weapon = &type;
}

HumanA::HumanA(std::string name, Weapon* type) {
	this->_name = name;
	this->_weapon = type;
}

HumanA::~HumanA(void) {
	return ;
}

void	HumanA::attack(void) const {
	std::cout << this->_name << "attacks with their " << this->_weapon->getType() << std::endl;
}

void	HumanA::setWeapon(Weapon& newWeapon) {
	this->_weapon = &newWeapon;
}

void	HumanA::setWeapon(Weapon* newWeapon) {
	this->_weapon = newWeapon;
}
