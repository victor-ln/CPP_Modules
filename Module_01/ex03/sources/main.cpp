/* Copyright © 2022 Victor Nunes, Licensed under the MIT License. */

#include "../includes/HumanA.hpp"
#include "../includes/HumanB.hpp"
#include "../includes/Weapon.hpp"

int main(void) {
    Weapon    *gun = new Weapon("Knife");
    {
        Weapon club = Weapon("crude spiked club");
        HumanA bob("Bob", club);
        bob.attack();
        club.setType("some other type of club");
        bob.attack();
        bob.setWeapon(gun);
        bob.attack();
    }
    {
        Weapon club = Weapon("crude spiked club");
        HumanB jim("Jim");
        jim.setWeapon(club);
        jim.attack();
        club.setType("some other type of club");
        jim.attack();
        jim.setWeapon(gun);
        jim.attack();
    }
    HumanB jimmy("Jimmy");
    jimmy.setWeapon(gun);
    jimmy.attack();
    gun->setType("Pistol");
    jimmy.attack();
    delete gun;
    return (0);
}
