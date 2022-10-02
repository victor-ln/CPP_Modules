/* Copyright © 2022 Victor Nunes, Licensed under the MIT License. */

#ifndef MODULE_00_EX01_INCLUDES_PHONEBOOK_HPP_
#define MODULE_00_EX01_INCLUDES_PHONEBOOK_HPP_

#define UNDERLINES            L"_____________________________________________"
#define OVERLINES             L"‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾"
#define MIDDLELINES           L"|----------+----------+----------+----------|"
#define PHONE_DIGITS          L"0123456789 -"
#define DIGITS                L"0123456789"

#define FIRSTNAME_MSG         L"Enter contact First name "
#define LASTNAME_MSG          L"Enter contact Last name "
#define NICKNAME_MSG          L"Enter contact Nickname "
#define SECRET_MSG            L"Enter contact Darkest secret "
#define PHONE_NB_MSG          L"Enter contact Phone Number "

#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <string>

#include "./Contact.hpp"

class PhoneBook {
 public:
    PhoneBook(void);

    void    add(void);
    void    search(void);

 private:
    Contact _contact[8];
    int     _last;
    int     _contactsAdded;

    Contact *_getLastContact(void);
    Contact *_getContactByIndex(int index);
    void    _getString(std::wstring message, std::wstring* to);
    void    _getPhoneNumber(std::wstring message, std::wstring* to);
    void    _displayContactInfo(void);
    int     _getIndexInput(void);
    void    _leftZerosTrim(std::wstring* input);
    int     _convertStrIndexToIntIndex(const std::wstring& input);
    void    _displayPipe(void);
    void    _displayTableUnderlines(void);
    void    _displayTableOverlines(void);
    void    _displayTableMiddleLines(void);
    void    _displayTableHead(void);
    void    _displayTableContent(const std::wstring& s);
};

bool    getInput(std::wstring message, std::wstring* to);

#endif /* MODULE_00_EX01_INCLUDES_PHONEBOOK_HPP_ */
