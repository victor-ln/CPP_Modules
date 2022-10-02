/* Copyright © 2022 Victor Nunes, Licensed under the MIT License. */

#ifndef MODULE_01_EX06_INCLUDES_HARL_HPP_
#define MODULE_01_EX06_INCLUDES_HARL_HPP_

#include <iostream>
#include <string>

class Harl {
 public:
    Harl();

    void complain(std::string level);

 private:
    std::string    funcNames[5];

    void    debug(void) const;
    void    info(void) const;
    void    warning(void) const;
    void    error(void) const;
};

#endif /* MODULE_01_EX06_INCLUDES_HARL_HPP_ */
