/* Copyright © 2022 Victor Nunes, Licensed under the MIT License. */

#include "../includes/Animal.hpp"
#include "../includes/Brain.hpp"
#include "../includes/Cat.hpp"
#include "../includes/Dog.hpp"

int main(void) {
    Animal      *animals[10];
    int         i = 0;

    while (i < 10) {
        if (i & 1)
            animals[i] = new Dog();
        else
            animals[i] = new Cat();
        ++i;
    }
    for (i = 0; i < 10; ++i)
        animals[i]->makeSound();
    for (i = 0; i < 10; ++i)
        delete animals[i];
    return (0);
}
