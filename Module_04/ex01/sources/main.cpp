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
    Dog     dog1;
    Dog     dog2;
    for (i = 0; i < 10; ++i) {
        dog1.newIdea("Bark");
        dog1.newIdea("Bark");
        dog2.newIdea("Howl");
    }
    std::cout << "\nDog1 Ideas:\n\n";
    dog1.showIdeas();
    std::cout << "\nDog2 Ideas:\n\n";
    dog2.showIdeas();
    std::cout << "\nCopying Dog2 into Dog1:\n\n";
    dog1 = dog2;
    std::cout << "\nDog1 Ideas:\n\n";
    dog1.showIdeas();
    for (i = 0; i < 10; ++i)
        animals[i]->makeSound();
    for (i = 0; i < 10; ++i)
        delete animals[i];
    return (0);
}
