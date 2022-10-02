/* Copyright © 2022 Victor Nunes, Licensed under the MIT License. */

#include "../includes/PhoneBook.hpp"

PhoneBook::PhoneBook(void) {
    this->_contactsAdded = 0;
    this->_last = 0;
}

void    PhoneBook::add(void) {
    Contact    *lastContact = this->_getLastContact();

    lastContact->clearContactData();
    this->_getString(FIRSTNAME_MSG, &lastContact->firstName);
    this->_getString(LASTNAME_MSG, &lastContact->lastName);
    this->_getString(NICKNAME_MSG, &lastContact->nickName);
    this->_getString(SECRET_MSG, &lastContact->darkestSecret);
    this->_getPhoneNumber(PHONE_NB_MSG, &lastContact->phoneNumber);
    if (!std::wcin.eof()) {
        std::wcout << L"✅ Contact added successfully" << std::endl;
        if (this->_contactsAdded < 8)
            this->_contactsAdded++;
    }
}

void    PhoneBook::search(void) {
    if (!this->_contactsAdded) {
        std::wcout << L"💥 There's no contacts added yet" << std::endl;
        return;
    }

    this->_displayTableUnderlines();
    this->_displayTableHead();

    Contact    *contact;
    int        index = 0;

    while (index < this->_contactsAdded) {
        contact = this->_getContactByIndex(index);
        this->_displayPipe();
        std::wcout << std::right << index;
        this->_displayTableContent(contact->firstName);
        this->_displayTableContent(contact->lastName);
        this->_displayTableContent(contact->nickName);
        this->_displayPipe();
        std::wcout << std::endl;
        if (++index < this->_contactsAdded)
            this->_displayTableMiddleLines();
    }
    this->_displayTableOverlines();
    this->_displayContactInfo();
}

inline Contact *PhoneBook::_getLastContact(void) {
    if (this->_last == 8)
        this->_last = 0;
    return (this->_contact + this->_last++);
}

inline Contact *PhoneBook::_getContactByIndex(int index) {
    return (this->_contact + index);
}

inline void    PhoneBook::_displayPipe(void) {
    std::wcout << std::setw(1) << L"|";
    std::wcout << std::setfill(L' ') << std::setw(10);
}

inline void    PhoneBook::_displayTableUnderlines(void) {
    std::wcout << UNDERLINES << std::endl;
}

inline void    PhoneBook::_displayTableOverlines(void) {
    std::wcout << OVERLINES << std::endl;
}

inline void    PhoneBook::_displayTableMiddleLines(void) {
    std::wcout << MIDDLELINES << std::endl;
}

void    PhoneBook::_getString(std::wstring message, std::wstring* to) {
    while (!std::wcin.eof() && !getInput(message, to))
        continue;
}

void    PhoneBook::_getPhoneNumber(std::wstring message, std::wstring* to) {
    while (!std::wcin.eof() && to->empty()) {
        if (getInput(message, to)) {
            if (to->find_first_not_of(PHONE_DIGITS) != std::wstring::npos || \
                to->find_first_of(DIGITS) == std::wstring::npos) {
                std::wcout << L"💥 Invalid input" << std::endl;
                to->clear();
            }
        }
    }
}

inline void    PhoneBook::_leftZerosTrim(std::wstring* input) {
    if (input->find_first_not_of(L"0") != std::wstring::npos)
        if (input->find_first_of(L"0") < input->find_first_not_of(L"0"))
            input->erase(0, input->find_first_not_of(L"0"));
}

int    PhoneBook::_convertStrIndexToIntIndex(const std::wstring& input) {
    char    tmp[input.length() + 1];
    size_t  i = 0;

    while (i < input.length()) {
        tmp[i] = static_cast<char>(input.at(i));
        i++;
    }
    tmp[i] = 0;
    return (atoi(tmp));
}

int    PhoneBook::_getIndexInput(void) {
    std::wstring        input;
    int                 index = 0;

    while (!std::wcin.eof() && input.empty()) {
        if (!getInput(L"Enter an index for details ", &input))
            continue;
        if (input.find_first_not_of(DIGITS) != std::wstring::npos) {
            std::wcout << L"💥 Invalid input" << std::endl;
            input.clear();
            continue;
        }
        this->_leftZerosTrim(&input);
        index = this->_convertStrIndexToIntIndex(input);
        if (index < 0 || index >= this->_contactsAdded) {
            std::wcout << L"💥 Invalid input, index out of range" << std::endl;
            input.clear();
        }
    }
    return (index);
}

void    PhoneBook::_displayTableHead(void) {
    this->_displayTableContent(L"Index");
    this->_displayTableContent(L"Firstname");
    this->_displayTableContent(L"Lastname");
    this->_displayTableContent(L"Nickname");
    this->_displayPipe();
    std::wcout << std::endl;
    this->_displayTableMiddleLines();
}

void    PhoneBook::_displayTableContent(const std::wstring& s) {
    this->_displayPipe();
    if (s.length() > 10)
        std::wcout << s.substr(0, 9) + L".";
    else
        std::wcout << std::right << s;
}

void    PhoneBook::_displayContactInfo(void) {
    int        index = this->_getIndexInput();
    Contact    *contact = this->_getContactByIndex(index);

    if (std::wcin.eof())
        return;
    std::wcout << std::setw(0) << std::endl;
    std::wcout << L"Firstname\t\t: " << contact->firstName << '\n';
    std::wcout << L"Lastname\t\t: " << contact->lastName << '\n';
    std::wcout << L"Nickname\t\t: " << contact->nickName << '\n';
    std::wcout << L"Darkest Secret\t\t: " << contact->darkestSecret << '\n';
    std::wcout << L"Phone number\t\t: " << contact->phoneNumber << '\n';
    std::wcout << std::endl;
}
