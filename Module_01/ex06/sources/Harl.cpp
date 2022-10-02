/* Copyright © 2022 Victor Nunes, Licensed under the MIT License. */

#include "../includes/Harl.hpp"

Harl::Harl(void) {
    this->funcNames[0] = "DEBUG";
    this->funcNames[1] = "INFO";
    this->funcNames[2] = "WARNING";
    this->funcNames[3] = "ERROR";
}

void    Harl::debug(void) const {
    std::cout << "[ DEBUG ]" << std::endl;
    std::cout << "I love having extra bacon for my"
                << " 7XL-double-cheese-triple-pickle-special-ketchup burger."
                << " I really do!" << std::endl;
}

void    Harl::info(void) const {
    std::cout << "[ INFO ]" << std::endl;
    std::cout << "I cannot believe adding extra bacon costs more money."
                << " You didn’t put enough bacon in my burger!"
                << " If you did, I wouldn’t be asking for more!" << std::endl;
}

void    Harl::warning(void) const {
    std::cout << "[ WARNING ]" << std::endl;
    std::cout << "I think I deserve to have some extra bacon for free."
                << " I’ve been coming for years whereas you started working"
                << " here since last month." << std::endl;
}

void    Harl::error(void) const {
    std::cout << "[ ERROR ]" << std::endl;
    std::cout << "This is unacceptable!"
                << " I want to speak to the manager now." << std::endl;
}

void    Harl::complain(std::string fName) {
    int        index = 0;

    while (index < 4) {
        if (this->funcNames[index] == fName)
            break;
        index++;
    }
    switch (index) {
        case 0:
            this->debug();
            __attribute__((fallthrough));
        case 1:
            this->info();
            __attribute__((fallthrough));
        case 2:
            this->warning();
            __attribute__((fallthrough));
        case 3:
            this->error();
            break;
        default:
            std::cout
                << "[ Probably complaining about insignificant problems ]"
                << std::endl;
    }
}
