/* Copyright © 2022 Victor Nunes, Licensed under the MIT License. */

#include "../includes/Harl.hpp"

Harl::Harl(void) {
    this->func[0] = &Harl::debug;
    this->func[1] = &Harl::info;
    this->func[2] = &Harl::warning;
    this->func[3] = &Harl::error;
    this->funcNames[0] = "DEBUG";
    this->funcNames[1] = "INFO";
    this->funcNames[2] = "WARNING";
    this->funcNames[3] = "ERROR";
}

void    Harl::debug(void) const {
    std::cout << "I love having extra bacon for my"
                << " 7XL-double-cheese-triple-pickle-special-ketchup burger."
                << " I really do!" << std::endl;
}

void    Harl::info(void) const {
    std::cout << "I cannot believe adding extra bacon costs more money."
                << " You didn’t put enough bacon in my burger!"
                << " If you did, I wouldn’t be asking for more!" << std::endl;
}

void    Harl::warning(void) const {
    std::cout << "I think I deserve to have some extra bacon for free."
                << " I’ve been coming for years whereas you started working"
                << " here since last month." << std::endl;
}

void    Harl::error(void) const {
    std::cout << "This is unacceptable!"
                << " I want to speak to the manager now." << std::endl;
}

void    Harl::complain(std::string fName) {
    for (int i = 0; i < 4; i++) {
        if (this->funcNames[i] == fName) {
            (this->*func[i])();
            return;
        }
    }
}
