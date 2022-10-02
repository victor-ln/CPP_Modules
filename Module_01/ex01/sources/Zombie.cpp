/* Copyright © 2022 Victor Nunes, Licensed under the MIT License. */

#include "../includes/Zombie.hpp"

Zombie::Zombie(std::string name) : _name(name) {
    std::cout << "Name Constructor Called" << '\n';
}

Zombie::Zombie(void) {
    std::cout << "Default Constructor Called" << '\n';
}

Zombie::~Zombie(void) {
    std::cout << "Destructor Called, Zombie name is: " << this->_name << '\n';
}

void    Zombie::announce(void) {
    std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
