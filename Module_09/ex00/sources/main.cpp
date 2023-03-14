/* Copyright © 2023 Victor Nunes, Licensed under the MIT License. */

#include <iostream>

#include "../includes/BitcoinExchange.hpp"

int main(int argc, char const *argv[]) {
    if (argc < 2) {
        std::cout << "Error: Invalid number of command arguments\n";
        return 1;
    }
    BitcoinExchange b;

    for (int i = 1; i < argc; i++) {
        std::cout << "\n" << argv[i] << "\n\n";
        b.execute(argv[i]);
    }
    return 0;
}
