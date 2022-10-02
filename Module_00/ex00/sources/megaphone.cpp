/* Copyright © 2022 Victor Nunes, Licensed under the MIT License. */

#include <iostream>

int main(int argc, char **argv) {
    if (argc == 1) {
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
    } else {
        for (int i = 1; i < argc; i++)
            while (*argv[i])
                std::cout << static_cast<char>(toupper(*argv[i]++));
    }
    std::cout << std::endl;
    return (0);
}
