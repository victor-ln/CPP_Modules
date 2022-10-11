/* Copyright © 2022 Victor Nunes, Licensed under the MIT License. */

#include "../includes/B.hpp"

B::B(void) : Base() {
    std::cout << "B: Constructor called\n";
}

B::~B(void) {
    std::cout << "B: Destructor called\n";
}
