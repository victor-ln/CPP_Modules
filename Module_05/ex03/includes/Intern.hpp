/* Copyright © 2022 Victor Nunes, Licensed under the MIT License. */

#ifndef MODULE_05_EX03_INCLUDES_INTERN_HPP_
#define MODULE_05_EX03_INCLUDES_INTERN_HPP_

#include <string>

#include "./PresidentialPardonForm.hpp"
#include "./Form.hpp"
#include "./RobotomyRequestForm.hpp"
#include "./ShrubberyCreationForm.hpp"

class Intern {
 public:
    Intern(void);
    Intern(const std::string&, const std::string&);
    Intern(const Intern&);
    ~Intern(void);

    Intern& operator=(const Intern& rhs);

    Form* makeForm(const std::string& formName, const std::string& target)const;
 private:
    Form  *_forms[3];
};

#endif /* MODULE_05_EX03_INCLUDES_INTERN_HPP_ */
