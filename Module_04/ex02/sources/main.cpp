/* Copyright © 2022 Victor Nunes, Licensed under the MIT License. */

#include "../includes/AbstractAnimal.hpp"
#include "../includes/Brain.hpp"
#include "../includes/Cat.hpp"
#include "../includes/Dog.hpp"

static void catsFunc(void);
static void dogsFunc(void);

int main(void) {
    AbstractAnimal      *animals[10];
    int         i = 0;

    std::cout << std::endl;
    while (i < 10) {
        if (i & 1)
            animals[i] = new Dog();
        else
            animals[i] = new Cat();
        std::cout << std::endl;
        ++i;
    }
    std::cout << std::endl;
    for (i = 0; i < 10; ++i)
        animals[i]->makeSound();
    std::cout << std::endl;
    for (i = 0; i < 10; ++i)
        delete animals[i];
    std::cout << std::endl;
    catsFunc();
    std::cout << std::endl;
    dogsFunc();
    return (0);
}

static void catsFunc(void) {
    Cat     cat1;
    Cat     cat2;

    cat1.newIdea("scratch the couch");
    cat1.showIdeas();
    cat2 = cat1;
    cat2.showIdeas();
    std::cout << std::endl;
}

static void dogsFunc(void) {
    Dog     dog1;
    Dog     dog2;

    dog1.newIdea("scratch the couch");
    dog1.showIdeas();
    dog2 = dog1;
    dog2.showIdeas();
    std::cout << std::endl;
}
