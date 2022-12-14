/* Copyright © 2022 Victor Nunes, Licensed under the MIT License. */

#include "../includes/PhoneBook.hpp"
#include "../includes/Contact.hpp"

static void help(void);
static void unknownCmd(void);

int main(void) {
    PhoneBook    phoneBookInstance;
    std::wstring userInput;

    std::ios_base::sync_with_stdio(false);
    std::wcin.imbue(std::locale("en_US.UTF-8"));
    std::wcout.imbue(std::locale("en_US.UTF-8"));
    help();
    while (!std::wcin.eof()) {
        if (!getInput(L"Enter a command : ", &userInput))
            continue;
        if (!userInput.compare(L"ADD")) {
            phoneBookInstance.add();
        } else if (!userInput.compare(L"SEARCH")) {
            phoneBookInstance.search();
        } else if (!userInput.compare(L"EXIT")) {
            std::wcout << L"Goodbye! 👋" << std::endl;
            break;
        } else if (!std::wcin.eof()) {
            unknownCmd();
        }
        userInput.clear();
    }
    return (0);
}

static void unknownCmd(void) {
    std::wcout << L"💥 Unknown command." << std::endl;
    help();
}

static void help(void) {
    std::wcout << L"Available commands are ";
    std::wcout << std::right << std::setfill(L'.') << std::setw(12);
    std::wcout << L" : " << std::endl << std::endl;
    std::wcout << L"ADD\t- Add a contact to the phone book";
    std::wcout << L"(It can store a maximum of 8 contacts)." << std::endl;
    std::wcout << L"SEARCH\t- Display contacts information in a table, ";
    std::wcout << L"then you can choose a specific one for more details.";
    std::wcout << std::endl;
    std::wcout << L"EXIT\t- Exits the program (all contacts are lost).";
    std::wcout << std::endl << std::endl;
}
