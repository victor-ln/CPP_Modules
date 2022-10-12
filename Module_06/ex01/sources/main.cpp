/* Copyright © 2022 Victor Nunes, Licensed under the MIT License. */

#include <iostream>

#include "../includes/Data.hpp"

int main(void) {
    Data    a = {5165161651};
    Data    *b = deserialize(serialize(&a));

    std::cout << "a:\t" << a.value << '\n';
    std::cout << "b:\t" << b->value << '\n';
    return (0);
}

uintptr_t   serialize(Data* ptr) {
    return (reinterpret_cast<uintptr_t>(ptr));
}

Data*       deserialize(uintptr_t raw) {
    return (reinterpret_cast<Data *>(raw));
}
