/* Copyright © 2022 Victor Nunes, Licensed under the MIT License. */

#ifndef MODULE_05_EX03_INCLUDES_FORM_HPP_
#define MODULE_05_EX03_INCLUDES_FORM_HPP_

#include <exception>
#include <iostream>
#include <string>

#include "./Bureaucrat.hpp"

class Bureaucrat;

class Form {
 public:
    Form(void);
    Form(const std::string& name, const int gToSign, const int gToExecute);
    Form(const Form&);
    virtual ~Form(void);

    Form&   operator=(const Form&);

    bool                isFormSigned(void) const;
    void                beSigned(const Bureaucrat&);
    int                 getGradeToSign(void) const;
    int                 getGradeToExecute(void) const;
    const std::string&  getName(void) const;
    virtual void        execute(const Bureaucrat& executor) const = 0;
    virtual Form*       clone(const std::string& target) const = 0;

 protected:
    class GradeTooHighException : public std::exception {
     public:
       explicit GradeTooHighException(const std::string&);
       ~GradeTooHighException(void) throw();

       const char* what(void) const throw();
     private:
       std::string _message;
    };

    class GradeTooLowException : public std::exception {
     public:
       explicit GradeTooLowException(const std::string&);
       ~GradeTooLowException(void) throw();

       const char* what(void) const throw();
     private:
       std::string _message;
    };

 private:
    const std::string   _name;
    const int           _gradeToSign;
    const int           _gradeToExecute;
    bool                _isFormSigned;
};

std::ostream&    operator<<(std::ostream&, Form&);

#endif /* MODULE_05_EX03_INCLUDES_FORM_HPP_ */
