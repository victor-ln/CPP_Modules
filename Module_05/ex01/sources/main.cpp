/* Copyright © 2022 Victor Nunes, Licensed under the MIT License. */

#include "../includes/Bureaucrat.hpp"
#include "../includes/Form.hpp"

int main(void) {
    try {
        Form    testHigh1("Test1", 0, 13);
    } catch(const std::exception& e) {
        std::cout << e.what() << '\n';
    }
    try {
        Form    testHigh2("Test2", -14, 23);
    } catch(const std::exception& e) {
        std::cout << e.what() << '\n';
    }
    try {
        Form    testLow1("Test3", 12, 197);
    } catch(const std::exception& e) {
        std::cout << e.what() << '\n';
    }
    try {
        Form    testLow2("Test4", 152, 1);
    } catch(const std::exception& e) {
        std::cout << e.what() << '\n';
    }

    Bureaucrat  a("Foo", 15);
    Bureaucrat  b = a;
    Form        form1("Check", 30, 14);
    Form        form2 = form1;

    std::cout << a << std::endl;
    std::cout << b << std::endl;
    a.signForm(&form1);
    std::cout << form1 << std::endl;
    std::cout << form2 << std::endl;
    return (0);
}
