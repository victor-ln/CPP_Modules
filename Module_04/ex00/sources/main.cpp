/* Copyright © 2022 Victor Nunes, Licensed under the MIT License. */

#include "../includes/Animal.hpp"
#include "../includes/Cat.hpp"
#include "../includes/Dog.hpp"

int main(void) {
    const Animal*   animal = new Animal();
    const Animal*   cat = new Cat();
    const Animal*   dog = new Dog();

    std::cout << animal->getType() << " " << std::endl;
    std::cout << cat->getType() << " " << std::endl;
    std::cout << dog->getType() << " " << std::endl;
    animal->makeSound();
    cat->makeSound();
    dog->makeSound();

    delete animal;
    delete cat;
    delete dog;
    return (0);
}
