/* Copyright © 2022 Victor Nunes, Licensed under the MIT License. */

#include "../includes/A.hpp"

A::A(void) : Base() {
    std::cout << "A: Constructor called\n";
}

A::~A(void) {
    std::cout << "A: Destructor called\n";
}
