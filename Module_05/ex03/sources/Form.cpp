/* Copyright © 2022 Victor Nunes, Licensed under the MIT License. */

#include "../includes/Form.hpp"

#define EXCEPTION_MSG "’s grade is too low to sign it."

#define EXCEPTION_HIGH_MSG "Exception: Grade too high"
#define EXCEPTION_LOW_MSG "Exception: Grade too low"

Form::Form(void) : _name("Default"), _gradeToSign(100), _gradeToExecute(100) {
    std::cout << "Form: Default constructor called" << std::endl;
    this->_isFormSigned = false;
}

Form::Form(const std::string& name, const int gradeSign, const int gradeExec) :
        _name(name), _gradeToSign(gradeSign), _gradeToExecute(gradeExec) {
    std::cout << "Form: Params constructor called" << std::endl;
    this->_isFormSigned = false;
}

Form::Form(const Form& src) : _name(src._name), _gradeToSign(src._gradeToSign),
        _gradeToExecute(src._gradeToExecute), _isFormSigned(src._isFormSigned) {
    if (_gradeToExecute <= 0 || _gradeToSign <= 0)
        throw GradeTooHighException(EXCEPTION_HIGH_MSG);
    if (_gradeToExecute > 150 || _gradeToSign > 150)
        throw GradeTooLowException(EXCEPTION_LOW_MSG);
    std::cout << "Form: Copy constructor called" << std::endl;
}

Form::~Form(void) {
    std::cout << "Form: Destructor called" << std::endl;
}

Form&   Form::operator=(const Form& rhs) {
    const_cast<std::string&>(this->_name) = rhs._name;
    const_cast<int&>(this->_gradeToExecute) = rhs._gradeToExecute;
    const_cast<int&>(this->_gradeToSign) = rhs._gradeToSign;
    const_cast<bool&>(this->_isFormSigned) = rhs._isFormSigned;
    return (*this);
}

Form::GradeTooHighException::~GradeTooHighException(void) throw() {}
Form::GradeTooLowException::~GradeTooLowException(void) throw() {}

Form::GradeTooHighException::GradeTooHighException(const std::string& reason) :
    _message(reason) {}

Form::GradeTooLowException::GradeTooLowException(const std::string& reason) :
    _message(reason) {}

const char* Form::GradeTooHighException::what(void) const throw() {
    return (_message.c_str());
}

const char* Form::GradeTooLowException::what(void) const throw() {
    return (_message.c_str());
}

std::ostream&   operator<<(std::ostream& cout, Form& form) {
    cout << "\tForm information\n";
    cout << "Form name: " << form.getName() << "\n";
    cout << "Is signed: " << (form.isFormSigned() ? "yes" : "no") << "\n";
    cout << "Grade to sign: " << form.getGradeToSign() << "\n";
    cout << "grade to execute: " << form.getGradeToExecute() << "\n";
    return (cout);
}

int Form::getGradeToSign(void) const {
    return (_gradeToSign);
}

int Form::getGradeToExecute(void) const {
    return (_gradeToExecute);
}

const std::string&  Form::getName(void) const {
    return (_name);
}

bool    Form::isFormSigned(void) const {
    return (_isFormSigned);
}

/**
 * If the bureaucrat's grade is lower than the form's grade to sign, throw a
 * GradeTooLowException. If the form has already been signed, throw a
 * GradeTooHighException. Otherwise, set the form's signed status to true and
 * print a message
 * 
 * @param b The bureaucrat that is signing the form
 */
void    Form::beSigned(const Bureaucrat& b) {
    if (b.getGrade() > _gradeToSign)
        throw GradeTooLowException(b.getName() + EXCEPTION_MSG);
    if (_isFormSigned)
        throw GradeTooHighException("Form has already been signed");
    _isFormSigned = true;
    std::cout << b.getName() << " signed " << this->_name << std::endl;
}
