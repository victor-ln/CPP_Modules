/* Copyright © 2022 Victor Nunes, Licensed under the MIT License. */

#include "../includes/Intern.hpp"

/**
 * Intern's default constructor initializes the array of pointers to
 * forms with the three types of forms.
 */
Intern::Intern(void) {
    std::cout << "Intern: Default constructor called" << std::endl;
    _forms[0] = new PresidentialPardonForm();
    _forms[1] = new RobotomyRequestForm();
    _forms[2] = new ShrubberyCreationForm();
}

Intern::Intern(const Intern& src) {
    std::cout << "Intern: Copy constructor called" << std::endl;
    _forms[0] = new PresidentialPardonForm();
    _forms[1] = new RobotomyRequestForm();
    _forms[2] = new ShrubberyCreationForm();
    (void)src;
}

Intern::~Intern(void) {
    std::cout << "Intern: Destructor called" << std::endl;
    for (int i = 0; i < 3; ++i)
        delete _forms[i];
}

Intern& Intern::operator=(const Intern& rhs) {
    (void)rhs;
    return (*this);
}

/**
 * It creates a form of the
 * given name, if it exists, and returns a pointer to it
 * 
 * @param formName The name of the form to create.
 * @param target the name of the target
 * 
 * @return A pointer to a Form.
 */
Form* Intern::makeForm(const std::string& formName, const std::string& target)
        const {
    for (int i = 0; i < 3; ++i) {
        if (formName == this->_forms[i]->getName()) {
            std::cout << "Intern creates " << formName << std::endl;
            return (this->_forms[i]->clone(target));
        }
    }
    std::cout << "Intern: Could not create form. Unknown form name.\n";
    return (0);
}
