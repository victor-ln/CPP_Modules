/* Copyright © 2022 Victor Nunes, Licensed under the MIT License. */

#include "../includes/Bureaucrat.hpp"
#include "../includes/Form.hpp"
#include "../includes/ShrubberyCreationForm.hpp"
#include "../includes/PresidentialPardonForm.hpp"
#include "../includes/RobotomyRequestForm.hpp"

int main(void) {
    Bureaucrat  a("Foo", 130);
    Form        *shrubberyForm = new ShrubberyCreationForm("forest");
    Form        *presidentialPardonForm = new PresidentialPardonForm("Bob");
    Form        *robotomyRequestForm = new RobotomyRequestForm("Arnold");

    a.signForm(shrubberyForm);
    a.executeForm(*shrubberyForm);
    a.signForm(presidentialPardonForm);
    std::cout << a << std::endl;
    while (presidentialPardonForm->getGradeToSign() < a.getGrade())
        ++a;
    Bureaucrat  b = a;
    std::cout << b << std::endl;
    a.signForm(presidentialPardonForm);
    a.executeForm(*presidentialPardonForm);
    while (presidentialPardonForm->getGradeToExecute() < a.getGrade())
        ++a;
    a.executeForm(*presidentialPardonForm);
    a.signForm(robotomyRequestForm);
    a.executeForm(*robotomyRequestForm);
    return (0);
}
