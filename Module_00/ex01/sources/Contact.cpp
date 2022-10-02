/* Copyright © 2022 Victor Nunes, Licensed under the MIT License. */

#include "../includes/Contact.hpp"

void Contact::clearContactData(void) {
    this->firstName.clear();
    this->lastName.clear();
    this->nickName.clear();
    this->phoneNumber.clear();
    this->darkestSecret.clear();
}
