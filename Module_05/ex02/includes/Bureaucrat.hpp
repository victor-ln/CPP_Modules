/* Copyright © 2022 Victor Nunes, Licensed under the MIT License. */

#ifndef MODULE_05_EX02_INCLUDES_BUREAUCRAT_HPP_
#define MODULE_05_EX02_INCLUDES_BUREAUCRAT_HPP_

#include <exception>
#include <iostream>
#include <string>

#include "./Form.hpp"

/**
 * Nested class:
 * 
 * A nested class is a class which is declared in another enclosing class. 
 * A nested class is a member and as such has the same access rights as any 
 * other member. The members of an enclosing class have no 
 * special access to members of a nested class.
 * 
*/

class Form;

class Bureaucrat {
 public:
    Bureaucrat(void);
    Bureaucrat(const Bureaucrat&);
    Bureaucrat(const std::string&, int);
    ~Bureaucrat(void);

    std::string     getName(void) const;
    int             getGrade(void) const;
    void            setGrade(int);
    void            signForm(Form*);
    void            executeForm(const Form&) const;

    Bureaucrat&     operator=(const Bureaucrat&);
    Bureaucrat&     operator++(void);
    Bureaucrat      operator++(int);
    Bureaucrat&     operator--(void);
    Bureaucrat      operator--(int);

 private:
    const std::string     _name;
    int                   _grade;

    class GradeTooHighException : public std::exception {
        const char* what(void) const throw();
    };
    class GradeTooLowException : public std::exception {
        const char* what(void) const throw();
    };
};

std::ostream&    operator<<(std::ostream&, Bureaucrat&);

#endif /* MODULE_05_EX02_INCLUDES_BUREAUCRAT_HPP_ */
