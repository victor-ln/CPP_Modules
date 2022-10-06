/* Copyright © 2022 Victor Nunes, Licensed under the MIT License. */

#include "../includes/AAnimal.hpp"
#include "../includes/Brain.hpp"
#include "../includes/Cat.hpp"
#include "../includes/Dog.hpp"

static void catsFunc(void);
static void dogsFunc(void);

int main(void) {
    AAnimal     *animals[10];
    int         i = 0;

    std::cout << "\n";
    while (i < 10) {
        if (i & 1)
            animals[i] = new Dog();
        else
            animals[i] = new Cat();
        std::cout << "\n";
        ++i;
    }
    std::cout << "\n";
    for (i = 0; i < 10; ++i)
        animals[i]->makeSound();
    std::cout << "\n";
    for (i = 0; i < 10; ++i)
        delete animals[i];
    std::cout << "\n";
    catsFunc();
    std::cout << "\n";
    dogsFunc();
    return (0);
}

static void catsFunc(void) {
    Cat     cat1;
    Cat     cat2;

    cat1.newIdea("scratch the couch");
    std::cout << "\n\tShowing ideas of cat 1\n\n";
    cat1.showIdeas();
    std::cout << "\n\tCopying cat 1 to cat 2\n\n";
    cat2 = cat1;
    std::cout << "\n\tShowing ideas of cat 2\n\n";
    cat2.showIdeas();
    std::cout << "\n";
}

static void dogsFunc(void) {
    Dog    *dog1 = new Dog();
    Dog     dog2;

    dog1->newIdea("catch a ball");
    std::cout << "\n\tShowing ideas of dog 1\n\n";
    dog1->showIdeas();
    std::cout << "\n\tCopying dog 1 to dog 2 and deleting dog 1\n\n";
    dog2 = *dog1;
    delete dog1;
    std::cout << "\n\tShowing ideas of dog 2\n\n";
    dog2.showIdeas();
    std::cout << "\n";
}
