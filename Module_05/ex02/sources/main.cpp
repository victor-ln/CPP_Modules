/* Copyright © 2022 Victor Nunes, Licensed under the MIT License. */

#include "../includes/Bureaucrat.hpp"
#include "../includes/Form.hpp"
#include "../includes/ShrubberyCreationForm.hpp"
#include "../includes/PresidentialPardonForm.hpp"
#include "../includes/RobotomyRequestForm.hpp"

int main(void) {
    Bureaucrat  a("Foo", 130);
    Form        *presidentialPardonForm = new PresidentialPardonForm("Bob");
    Form        *robotomyRequestForm = new RobotomyRequestForm("Arnold");
    ShrubberyCreationForm        *shrubberyForm = new ShrubberyCreationForm("forest");
    Form        *shrubberyForm2 = new ShrubberyCreationForm(*shrubberyForm);

    std::cout << "\n\tBureaucrat signing forms\n\n";
    a.signForm(shrubberyForm);
    a.executeForm(*shrubberyForm);
    std::cout << *shrubberyForm << std::endl;
    std::cout << *shrubberyForm2 << std::endl;
    std::cout << '\n';
    a.signForm(presidentialPardonForm);
    std::cout << a << "\n";
    while (presidentialPardonForm->getGradeToSign() < a.getGrade())
        ++a;
    Bureaucrat  b = a;
    std::cout << b << "\n";
    std::cout << '\n';
    a.signForm(presidentialPardonForm);
    std::cout << '\n';
    a.executeForm(*presidentialPardonForm);
    while (presidentialPardonForm->getGradeToExecute() < a.getGrade())
        ++a;
    std::cout << '\n';
    a.executeForm(*presidentialPardonForm);
    std::cout << '\n';
    a.signForm(robotomyRequestForm);
    std::cout << '\n';
    a.executeForm(*robotomyRequestForm);
    std::cout << '\n';
    return (0);
}
