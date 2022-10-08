/* Copyright © 2022 Victor Nunes, Licensed under the MIT License. */

#include "../includes/ShrubberyCreationForm.hpp"

#define EXCEPTION_EXEC_MSG "’s grade is too low to execute it."
#define EXCEPTION_SIGN_MSG "form is not signed yet."
#define SUCCESS_MSG " has been pardoned by Zaphod Beeblebrox."

ShrubberyCreationForm::ShrubberyCreationForm(void) :
        Form("Shrubbery Creation Form", 145, 137) {
    std::cout << "ShrubberyForm: Default Constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target) :
        Form("Shrubbery Creation Form", 145, 137) {
    std::cout << "ShrubberyForm: Target Constructor called" << std::endl;
    _target = target + "_shrubbery";
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& rhs) :
        Form(rhs), _target(rhs._target) {
    std::cout << "PresidentialForm: Copy Constructor called" << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm(void) {
    std::cout << "ShrubberyForm: Destructor called" << std::endl;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(
        const ShrubberyCreationForm& rhs) {
    Form    *tmp1 = this;
    Form    *tmp2 = const_cast<ShrubberyCreationForm*>(&rhs);

    *tmp1 = *tmp2;
    this->_target = rhs._target;
    return (*this);
}

void    ShrubberyCreationForm::execute(const Bureaucrat& b) const {
    if (!this->isFormSigned())
        throw GradeTooLowException(EXCEPTION_SIGN_MSG);
    if (b.getGrade() > this->getGradeToExecute())
        throw GradeTooLowException(b.getName() + EXCEPTION_EXEC_MSG);
    std::ofstream    shrubberyFile;
    shrubberyFile.open(_target.c_str(), std::ios::out | std::ios::app);
    shrubberyFile << TREE;
    shrubberyFile.close();
    std::cout << b.getName() << " executed " << this->getName() << std::endl;
    std::cout << "Shrubbery planted in " << _target << " file." << std::endl;
}
