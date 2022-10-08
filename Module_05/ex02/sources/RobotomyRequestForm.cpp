/* Copyright © 2022 Victor Nunes, Licensed under the MIT License. */

#include "../includes/RobotomyRequestForm.hpp"

#define EXCEPTION_EXEC_MSG "’s grade is too low to execute it. The robotomy failed."
#define EXCEPTION_SIGN_MSG "form is not signed yet."
#define SUCCESS_MSG " has been robotomized successfully 50% of the time"

RobotomyRequestForm::RobotomyRequestForm(void) :
        Form("Robotomy Request Form", 72, 45) {
    std::cout << "RobotomyForm: Default Constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const std::string& target) :
        Form("Robotomy Request Form", 72, 45), _target(target) {
    std::cout << "RobotomyForm: Target Constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& rhs) :
        Form(rhs), _target(rhs._target) {
    std::cout << "PresidentialForm: Copy Constructor called" << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm(void) {
    std::cout << "RobotomyForm: Destructor called" << std::endl;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(
        const RobotomyRequestForm& rhs) {
    Form    *tmp1 = this;
    Form    *tmp2 = const_cast<RobotomyRequestForm*>(&rhs);

    *tmp1 = *tmp2;
    this->_target = rhs._target;
    return (*this);
}

/**
 * If the form is signed and the bureaucrat's grade is high enough, the bureaucrat
 * executes the form and prints a success message
 * 
 * @param b The bureaucrat that is executing the form.
 */
void    RobotomyRequestForm::execute(const Bureaucrat& b) const {
    if (!this->isFormSigned())
        throw GradeTooLowException(EXCEPTION_SIGN_MSG);
    if (b.getGrade() > this->getGradeToExecute())
        throw GradeTooLowException(b.getName() + EXCEPTION_EXEC_MSG);
    std::cout << b.getName() << " executed " << this->getName() << std::endl;
    std::cout << _target << SUCCESS_MSG << std::endl;
}
