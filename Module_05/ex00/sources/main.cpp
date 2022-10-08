/* Copyright © 2022 Victor Nunes, Licensed under the MIT License. */

#include "../includes/Bureaucrat.hpp"

int main(void) {
    try {
        Bureaucrat  a("Amy", 0);
    } catch (const std::exception& e) {
        std::cout << e.what() << std::endl;
    }
    try {
        Bureaucrat  a("John", 151);
    } catch (const std::exception& e) {
        std::cout << e.what() << std::endl;
    }
    Bureaucrat  a("Bob", 15);
    Bureaucrat  b = a;
    std::cout << a << std::endl;
    std::cout << b << std::endl;
    while (a.getGrade()) {
        try {
            ++a;
        } catch (const std::exception &e) {
            std::cout << e.what() << std::endl;
            break;
        }
    }
    std::cout << a << std::endl;
    while (a.getGrade() <= 150) {
        try {
            --a;
        } catch (const std::exception &e) {
            std::cout << e.what() << std::endl;
            break;
        }
    }
    std::cout << a << std::endl;
    return 0;
}
