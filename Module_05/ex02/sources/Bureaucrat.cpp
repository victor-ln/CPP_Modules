/* Copyright © 2022 Victor Nunes, Licensed under the MIT License. */

#include "../includes/Bureaucrat.hpp"

Bureaucrat::Bureaucrat(void) : _name("Form"), _grade(75) {
    std::cout << "Bureaucrat: Default constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat& rhs) : _name(rhs._name),
        _grade(rhs._grade) {
    std::cout << "Bureaucrat: Copy constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(const std::string& name, int grade) : _name(name) {
    std::cout << "Bureaucrat: [Name, grade] constructor called" << std::endl;
    if (grade <= 0) {
        throw GradeTooHighException();
    } else if (grade > 150) {
        throw GradeTooLowException();
    }
    _grade = grade;
}

Bureaucrat::~Bureaucrat(void) {
    std::cout << "Bureaucrat: Destructor called" << std::endl;
}

const char* Bureaucrat::GradeTooHighException::what(void) const throw() {
    return ("Exception: Grade too high");
}

const char* Bureaucrat::GradeTooLowException::what(void) const throw() {
    return ("Exception: Grade too low");
}

Bureaucrat&     Bureaucrat::operator=(const Bureaucrat& rhs) {
    this->_grade = rhs._grade;
    const_cast<std::string&>(this->_name) = rhs._name;
    return (*this);
}

Bureaucrat Bureaucrat::operator--(int) {
    if (_grade + 1 > 150) {
        throw GradeTooLowException();
    }
    Bureaucrat  tmp(_name, _grade);
    _grade++;
    return (tmp);
}

Bureaucrat& Bureaucrat::operator--(void) {
    if (_grade + 1 > 150) {
        throw GradeTooLowException();
    }
    _grade++;
    return (*this);
}

Bureaucrat Bureaucrat::operator++(int) {
    if (_grade - 1 <= 0) {
        throw GradeTooHighException();
    }
    Bureaucrat  tmp(_name, _grade);
    _grade--;
    return (tmp);
}

Bureaucrat& Bureaucrat::operator++(void) {
    if (_grade - 1 <= 0) {
        throw GradeTooHighException();
    }
    _grade--;
    return (*this);
}

std::ostream&    operator<<(std::ostream& cout, Bureaucrat& b) {
    return (cout << b.getName() << ", bureaucrat grade " << b.getGrade());
}

std::string     Bureaucrat::getName(void) const {
    return (_name);
}

int     Bureaucrat::getGrade(void) const {
    return (_grade);
}

void    Bureaucrat::signForm(Form* form) {
    try {
        form->beSigned(*this);
    } catch(const std::exception& e) {
        std::cout << _name << " couldn’t sign " << form->getName()
                    << " because " << e.what() << std::endl;
        return;
    }
}

void    Bureaucrat::executeForm(const Form& form) const {
    try {
        form.execute(*this);
    } catch (const std::exception& e) {
        std::cout << _name << " couldn’t execute " << form.getName()
                    << " because " << e.what() << std::endl;
        return;
    }
}
