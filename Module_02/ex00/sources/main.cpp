/* Copyright © 2022 Victor Nunes, Licensed under the MIT License. */

#include "../includes/Fixed.hpp"

int    main(void) {
    Fixed    a;
    Fixed    b(a);
    Fixed    c;

    c = b;
    std::cout << a.getRawBits() << std::endl;
    std::cout << b.getRawBits() << std::endl;
    std::cout << c.getRawBits() << std::endl;
    return (0);
}
