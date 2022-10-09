/* Copyright © 2022 Victor Nunes, Licensed under the MIT License. */

#include "../includes/Bureaucrat.hpp"
#include "../includes/Form.hpp"
#include "../includes/Intern.hpp"
#include "../includes/PresidentialPardonForm.hpp"
#include "../includes/RobotomyRequestForm.hpp"
#include "../includes/ShrubberyCreationForm.hpp"

int main(void) {
    Bureaucrat  a("Foo", 130);
    Intern      someRandomIntern;
    Form        *ppForm;
    Form        *rrForm;
    Form        *scForm;
    Form        *form;

    std::cout << "\n\tIntern Creating forms\n\n";
    ppForm = someRandomIntern.makeForm("presidential pardon", "Bob");
    rrForm = someRandomIntern.makeForm("robotomy request", "Arnold");
    scForm = someRandomIntern.makeForm("shrubbery creation", "forest");
    form = someRandomIntern.makeForm("form", "forest");
    (void)form;
    std::cout << "\n\tBureaucrat signing forms\n\n";
    a.signForm(scForm);
    a.executeForm(*scForm);
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
    delete ppForm;
    delete rrForm;
    delete scForm;
    delete form;
    return (0);
}
