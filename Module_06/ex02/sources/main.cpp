/* Copyright © 2022 Victor Nunes, Licensed under the MIT License. */

#include "../includes/A.hpp"
#include "../includes/Base.hpp"
#include "../includes/B.hpp"
#include "../includes/C.hpp"

Base* generate(void);
void identify(Base* p);
void identify(Base& p);

int main(void) {
    Base    *p1 = generate();
    Base    *p2 = generate();
    Base    *p3 = generate();
    Base    *p4 = generate();
    Base    *p5 = new C;

    std::cout << "\nRandom\n\n";
    identify(p1);
    identify(p2);
    identify(p3);
    identify(p4);
    identify(*p1);
    identify(*p2);
    identify(*p3);
    identify(*p4);
    std::cout << "\nDeclared\n\n";
    identify(p5);
    identify(*p5);
    std::cout << '\n';

    delete  p1;
    delete  p2;
    delete  p3;
    delete  p4;
    delete  p5;
    return (0);
}

Base* generate(void) {
    switch (rand() % 3) {
        case 0:
            srand((unsigned int)time(NULL));
            return (new A);
        case 1:
            srand((unsigned int)time(NULL));
            return (new B);
        case 2:
            srand((unsigned int)time(NULL));
            return (new C);
    }
    return (0);
}

void identify(Base* p) {
    A   *a = dynamic_cast<A *>(p);
    B   *b = dynamic_cast<B *>(p);

    std::cout << "The derived class is: ";
    if (a) {
        std::cout << "A";
    } else if (b) {
        std::cout << "B";
    } else {
        std::cout << "C";
    }
    std::cout << '\n';
}

void identify(Base& p) {
    std::cout << "The derived class is: ";
    try {
        A   &a = dynamic_cast<A&>(p);
        (void)a;
    } catch(...) {
        try {
            B   &b = dynamic_cast<B&>(p);
            (void)b;
        } catch (...) {
            std::cout << "C\n";
            return;
        }
        std::cout << "B\n";
        return;
    }
    std::cout << "A\n";
}
