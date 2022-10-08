/* Copyright © 2022 Victor Nunes, Licensed under the MIT License. */

#ifndef MODULE_05_EX03_INCLUDES_PRESIDENTIALPARDONFORM_HPP_
#define MODULE_05_EX03_INCLUDES_PRESIDENTIALPARDONFORM_HPP_

#include "./Form.hpp"

class PresidentialPardonForm : public Form {
 public:
    PresidentialPardonForm(void);
    explicit PresidentialPardonForm(const std::string& target);
    PresidentialPardonForm(const PresidentialPardonForm&);
    ~PresidentialPardonForm(void);

    PresidentialPardonForm&   operator=(const PresidentialPardonForm&);

    void execute(const Bureaucrat& executor) const;

 private:
    std::string      _target;
};

#endif /* MODULE_05_EX03_INCLUDES_PRESIDENTIALPARDONFORM_HPP_ */
