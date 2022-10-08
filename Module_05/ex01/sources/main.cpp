/* Copyright © 2022 Victor Nunes, Licensed under the MIT License. */

#include "../includes/Bureaucrat.hpp"
#include "../includes/Form.hpp"

int main(void) {
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
