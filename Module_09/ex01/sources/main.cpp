/* Copyright © 2023 Victor Nunes, Licensed under the MIT License. */

#include <iostream>

#include "../includes/RPN.hpp"

int main(int argc, char const *argv[]) {
    if (argc < 2) {
        std::cout << "Error: Invalid number of command arguments\n";
        return 1;
    }
    RPN rpn;

    for (int i = 1; i < argc; i++) {
        rpn.execute(argv[i]);
    }
    return 0;
}
