/* Copyright © 2022 Victor Nunes, Licensed under the MIT License. */

#include "../includes/C.hpp"

C::C(void) : Base() {
    std::cout << "C: Constructor called\n";
}

C::~C(void) {
    std::cout << "C: Destructor called\n";
}
