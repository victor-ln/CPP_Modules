/* Copyright © 2022 Victor Nunes, Licensed under the MIT License. */

#include "../includes/PresidentialPardonForm.hpp"

#define EXCEPTION_EXEC_MSG "’s grade is too low to execute it."
#define EXCEPTION_SIGN_MSG "form is not signed yet."
#define SUCCESS_MSG " has been pardoned by Zaphod Beeblebrox."

PresidentialPardonForm::PresidentialPardonForm(void) :
        Form("presidential pardon", 25, 5) {
    std::cout << "PresidentialForm: Default Constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const std::string& target) :
        Form("presidential pardon", 25, 5), _target(target) {
    std::cout << "PresidentialForm: Target Constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(
        const PresidentialPardonForm& rhs) : Form(rhs), _target(rhs._target) {
    std::cout << "PresidentialForm: Copy Constructor called" << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm(void) {
    std::cout << "PresidentialForm: Destructor called" << std::endl;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(
        const PresidentialPardonForm& rhs) {
    Form    *tmp1 = this;
    Form    *tmp2 = const_cast<PresidentialPardonForm*>(&rhs);

    *tmp1 = *tmp2;
    this->_target = rhs._target;
    return (*this);
}

void    PresidentialPardonForm::execute(const Bureaucrat& b) const {
    if (!this->isFormSigned())
        throw GradeTooLowException(EXCEPTION_SIGN_MSG);
    if (b.getGrade() > this->getGradeToExecute())
        throw GradeTooLowException(b.getName() + EXCEPTION_EXEC_MSG);
    std::cout << b.getName() << " executed " << this->getName() << std::endl;
    std::cout << _target << SUCCESS_MSG << std::endl;
}

Form* PresidentialPardonForm::clone(const std::string& target) const {
    return (new PresidentialPardonForm(target));
}
