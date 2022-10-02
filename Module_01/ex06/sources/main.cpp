/* Copyright © 2022 Victor Nunes, Licensed under the MIT License. */

#include "../includes/Harl.hpp"

int main(int argc, char **argv) {
    if (argc != 2) {
        std::cout << "Invalid number of arguments" << std::endl;
        return (0);
    }
    Harl    harl;

    harl.complain(argv[1]);
    return (0);
}
