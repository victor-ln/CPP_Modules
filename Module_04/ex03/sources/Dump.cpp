/* Copyright © 2022 Victor Nunes, Licensed under the MIT License. */

#include "../includes/Dump.hpp"

Dump::Dump(void) : _head(0) {
    std::cout << "Dump: Constructor called" << std::endl;
}

Dump::Dump(const Dump& src) {
    *this = src;
}

Dump::~Dump(void) {
    std::cout << "Dump: Destructor called" << std::endl;
    Node    *next = 0;

    while (_head) {
        next = _head->next;
        delete _head->data;
        delete _head;
        _head = next;
    }
    _head = 0;
}

Dump    Dump::operator=(const Dump& rhs) {
    (void)rhs;
    return (*this);
}

void Dump::push(AMateria *m) {
    Node    *newNode = new Node;

    newNode->data = m;
    newNode->next = _head;
    _head = newNode;
}
