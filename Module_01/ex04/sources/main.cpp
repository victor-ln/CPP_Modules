/* Copyright © 2022 Victor Nunes, Licensed under the MIT License. */

#include "../includes/Sed.hpp"

int main(int argc, char **argv) {
    if (argc != 4) {
        std::cout << "Invalid number of arguments" << std::endl;
        return (0);
    }
    Sed        sed(argv[1], argv[2], argv[3]);

    sed.execute();
    return (0);
}
