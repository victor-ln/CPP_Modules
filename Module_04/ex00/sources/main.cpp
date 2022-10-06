/* Copyright © 2022 Victor Nunes, Licensed under the MIT License. */

#include "../includes/Animal.hpp"
#include "../includes/Cat.hpp"
#include "../includes/Dog.hpp"
#include "../includes/WrongAnimal.hpp"
#include "../includes/WrongCat.hpp"

int main(void) {
    const Animal*        animal = new Animal();
    const Animal*        cat = new Cat();
    const WrongAnimal*   wCat = new WrongCat();
    const Animal*        dog = new Dog();

    std::cout << animal->getType() << " " << std::endl;
    std::cout << cat->getType() << " " << std::endl;
    std::cout << dog->getType() << " " << std::endl;
    animal->makeSound();
    dog->makeSound();
    cat->makeSound();
    wCat->makeSound();

    delete animal;
    delete cat;
    delete dog;
    delete wCat;
    return (0);
}
