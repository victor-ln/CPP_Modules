/* Copyright © 2022 Victor Nunes, Licensed under the MIT License. */

#ifndef MODULE_00_EX01_INCLUDES_CONTACT_HPP_
#define MODULE_00_EX01_INCLUDES_CONTACT_HPP_

#include <iostream>
#include <string>

class Contact {
 public:
    std::wstring        phoneNumber;
    std::wstring        firstName;
    std::wstring        lastName;
    std::wstring        nickName;
    std::wstring        darkestSecret;

    void    clearContactData(void);
};

#endif /* MODULE_00_EX01_INCLUDES_CONTACT_HPP_ */
