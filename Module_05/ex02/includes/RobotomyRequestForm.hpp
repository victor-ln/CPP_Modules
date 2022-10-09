/* Copyright © 2022 Victor Nunes, Licensed under the MIT License. */

#ifndef MODULE_05_EX02_INCLUDES_ROBOTOMYREQUESTFORM_HPP_
#define MODULE_05_EX02_INCLUDES_ROBOTOMYREQUESTFORM_HPP_

#include <iostream>
#include <string>

#include "./Form.hpp"

class RobotomyRequestForm : public Form {
 public:
    RobotomyRequestForm(void);
    explicit RobotomyRequestForm(const std::string& target);
    RobotomyRequestForm(const RobotomyRequestForm&);
    ~RobotomyRequestForm(void);

    RobotomyRequestForm&   operator=(const RobotomyRequestForm&);

    void        execute(const Bureaucrat& executor) const;

 private:
    std::string      _target;
};

#endif /* MODULE_05_EX02_INCLUDES_ROBOTOMYREQUESTFORM_HPP_ */
