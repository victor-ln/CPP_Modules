/* Copyright © 2022 Victor Nunes, Licensed under the MIT License. */

#include "../includes/AMateria.hpp"
#include "../includes/Cure.hpp"
#include "../includes/Ice.hpp"
#include "../includes/Character.hpp"
#include "../includes/MateriaSource.hpp"

int main(void) {
    IMateriaSource  *src = new MateriaSource();
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());
    ICharacter  *me = new Character("me");
    AMateria    *tmp;
    tmp = src->createMateria("ice");
    me->equip(tmp);
    tmp = src->createMateria("cure");
    me->equip(tmp);
    ICharacter  *bob = new Character("bob");
    me->use(0, *bob);
    me->use(1, *bob);

    std::cout << "\n\tTesting... Creating ice in 2nd slot and using it\n\n";
    tmp = src->createMateria("ice");
    me->equip(tmp);
    me->use(2, *bob);
    std::cout << "\n\tTesting... Unequipping slots 1 and 2...\n\n";
    me->unequip(1);
    me->unequip(2);
    std::cout << "\n\tAnd trying to use them\n\n";
    me->use(1, *bob);
    me->use(2, *bob);
    std::cout << "\n";

    delete bob;
    delete me;
    delete src;
    return (0);
}
