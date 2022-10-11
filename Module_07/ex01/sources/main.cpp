/* Copyright © 2022 Victor Nunes, Licensed under the MIT License. */

#include <iostream>

#include "../includes/iter.hpp"

template<int nb>
void sum(int& a) {
    a += nb;
}

void print_and_space(const char *s) {
    std::cout << s << ' ';
}

int main(void) {
    int     vector[5] = {1, 2, 3, 4, 5};
    char    strs[3][10] = {"Hello", "World", "!"};

    std::cout << "\n\tBefore:\n";
    for (size_t i = 0; i < 5; i++)
        std::cout << vector[i] << "\n";
    std::cout << '\n';

    iter(vector, 5, sum<15>);
    std::cout << "\n\tAfter:\n";
    for (size_t i = 0; i < 5; i++)
        std::cout << vector[i] << "\n";
    std::cout << '\n';

    iter(strs, 3, print_and_space);
    std::cout << '\n';
    return (0);
}
