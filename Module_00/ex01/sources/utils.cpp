/* Copyright © 2022 Victor Nunes, Licensed under the MIT License. */

#include "../includes/PhoneBook.hpp"

#define SPACE    L" \t\n\r\f\v"

static inline void    strtrim(std::wstring* s);

bool    getInput(std::wstring message, std::wstring* to) {
    std::wcout << message;
    std::wcout << std::setfill(L'.') << std::setw(35 - message.length());
    std::wcout << L" : " << std::endl;
    std::wcin.clear();
    std::wcin.sync();
    std::getline(std::wcin, *to);
    strtrim(to);
    return (!to->empty());
}

static inline void    strtrim(std::wstring* s) {
    s->erase(s->find_last_not_of(SPACE) + 1);
    s->erase(0, s->find_first_not_of(SPACE));
}
