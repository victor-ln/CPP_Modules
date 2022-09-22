#include "Zombie.hpp"

Zombie::Zombie(std::string name) : _name(name) {
	return ;
}

Zombie::Zombie(void) {
	return ;
}

Zombie::~Zombie() {
	std::cout << "Destructor Called" << std::endl;
	std::cout << "Zombie name is: " << this->_name << std::endl;
}

void	Zombie::announce(void) {
	std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
