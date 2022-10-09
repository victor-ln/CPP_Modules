/* Copyright © 2022 Victor Nunes, Licensed under the MIT License. */

#include "../includes/Bureaucrat.hpp"
#include "../includes/Form.hpp"
#include "../includes/ShrubberyCreationForm.hpp"
#include "../includes/PresidentialPardonForm.hpp"
#include "../includes/RobotomyRequestForm.hpp"

int main(void) {
    Bureaucrat  a("Foo", 130);
    Form        *ppForm = new PresidentialPardonForm("Bob");
    Form        *rrForm = new RobotomyRequestForm("Arnold");
    ShrubberyCreationForm *scForm1 = new ShrubberyCreationForm("forest");
    Form        *scForm2 = new ShrubberyCreationForm(*scForm1);

    std::cout << "\n\tBureaucrat signing forms\n\n";
    a.signForm(scForm1);
    a.executeForm(*scForm1);
    std::cout << *scForm1 << std::endl;
    std::cout << *scForm2 << std::endl;
    std::cout << '\n';
    a.signForm(ppForm);
    std::cout << a << "\n";
    while (ppForm->getGradeToSign() < a.getGrade())
        ++a;
    Bureaucrat  b = a;
    std::cout << b << "\n";
    std::cout << '\n';
    a.signForm(ppForm);
    std::cout << '\n';
    a.executeForm(*ppForm);
    while (ppForm->getGradeToExecute() < a.getGrade())
        ++a;
    std::cout << '\n';
    a.executeForm(*ppForm);
    std::cout << '\n';
    a.signForm(rrForm);
    std::cout << '\n';
    a.executeForm(*rrForm);
    std::cout << '\n';
    return (0);
}
