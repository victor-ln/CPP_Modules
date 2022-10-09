/* Copyright © 2022 Victor Nunes, Licensed under the MIT License. */

#include "../includes/ShrubberyCreationForm.hpp"

#define EXCEPTION_EXEC_MSG "’s grade is too low to execute it."
#define EXCEPTION_SIGN_MSG "form is not signed yet."
#define SUCCESS_MSG " has been pardoned by Zaphod Beeblebrox."

ShrubberyCreationForm::ShrubberyCreationForm(void) :
        Form("shrubbery creation", 145, 137) {
    std::cout << "ShrubberyForm: Default Constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target) :
        Form("shrubbery creation", 145, 137), _target(target) {
    std::cout << "ShrubberyForm: Target Constructor called" << std::endl;
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

/**
 * If the form is signed and the bureaucrat's grade is high enough,
 * it opens a file with the name of the target, 
 * appends the tree ASCII art to it, and closes the file.
 * 
 * @param b the bureaucrat that is executing the form
 */
void    ShrubberyCreationForm::execute(const Bureaucrat& b) const {
    if (!this->isFormSigned())
        throw GradeTooLowException(EXCEPTION_SIGN_MSG);
    if (b.getGrade() > this->getGradeToExecute())
        throw GradeTooLowException(b.getName() + EXCEPTION_EXEC_MSG);
    std::ofstream    shrubberyFile;
    std::string     filename = _target + "_shrubbery";
    shrubberyFile.open(filename.c_str(), std::ios::out | std::ios::app);
    shrubberyFile << TREE;
    shrubberyFile.close();
    std::cout << b.getName() << " executed " << this->getName() << std::endl;
    std::cout << "Shrubbery planted in " << _target << " file." << std::endl;
}

Form* ShrubberyCreationForm::clone(const std::string& target) const {
    return (new ShrubberyCreationForm(target));
}
