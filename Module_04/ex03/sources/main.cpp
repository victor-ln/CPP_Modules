/* Copyright © 2022 Victor Nunes, Licensed under the MIT License. */

#include "../includes/AMateria.hpp"
#include "../includes/Cure.hpp"
#include "../includes/Ice.hpp"
#include "../includes/Character.hpp"
#include "../includes/MateriaSource.hpp"

static void    testLearningMateria(IMateriaSource *src);
static void    testEquippingAndUsing(IMateriaSource *src, ICharacter *me, \
                                        ICharacter *bob);
static void    testUnequippingAndUsing(ICharacter *me, ICharacter *bob);
static void    testCopyCharacter(IMateriaSource *src, ICharacter *target);

int main(void) {
    IMateriaSource  *src = new MateriaSource();
    testLearningMateria(src);
    ICharacter  *me = new Character("me");
    ICharacter  *bob = new Character("bob");
    testEquippingAndUsing(src, me, bob);
    testUnequippingAndUsing(me, bob);
    testCopyCharacter(src, bob);
    delete bob;
    delete me;
    delete src;
    return (0);
}

static void    testLearningMateria(IMateriaSource *src) {
    std::cout << "\n\tTesting... Learning materias\n\n";
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());
    std::cout << "\n\tAdding more than four materias\n\n";
    AMateria *tmp = new Ice();
    std::cout << "\n";
    src->learnMateria(tmp);
    std::cout << "\n";
    delete tmp;
    tmp = new Cure();
    std::cout << "\n";
    src->learnMateria(tmp);
    std::cout << "\n";
    delete tmp;
    std::cout << "\n";
}

static void    testEquippingAndUsing(IMateriaSource *src, ICharacter *me, \
                                        ICharacter *bob) {
    AMateria    *tmp;
    tmp = src->createMateria("ice");
    me->equip(tmp);
    tmp = src->createMateria("cure");
    me->equip(tmp);
    me->use(0, *bob);
    me->use(1, *bob);
}

static void    testUnequippingAndUsing(ICharacter *me, ICharacter *bob) {
    std::cout << "\n\tTesting... Unequipping slots 1 and 2...\n\n";
    me->unequip(1);
    me->unequip(2);
    std::cout << "\n\tAnd trying to use them\n\n";
    me->use(1, *bob);
    me->use(2, *bob);
    std::cout << "\n";
}

static void    testCopyCharacter(IMateriaSource *src, ICharacter *target) {
    std::cout << "\n\tTesting... Creating new character and equiping him\n\n";
    Character  *john = new Character("John");
    john->equip(src->createMateria("ice"));
    std::cout << "\n\tCreating another new character\n\n";
    Character  *johnJr = new Character();
    std::cout << "\n\tTrying to use a materia\n\n";
    johnJr->use(0, *target);
    std::cout << "\n\tCopying character to the newest one\n\n";
    *johnJr = *john;
    std::cout << "\n\tTrying to use a materia again\n\n";
    johnJr->use(0, *target);

    delete john;
    delete johnJr;
}
