/* Copyright © 2022 Victor Nunes, Licensed under the MIT License. */

#ifndef MODULE_07_EX00_INCLUDES_ITER_HPP_
#define MODULE_07_EX00_INCLUDES_ITER_HPP_

#include <iostream>

template<typename T, typename function>
void iter(T *address, size_t end, function func) {
    for (size_t i = 0; i < end; i++) {
        func(*address);
        ++address;
    }
}

#endif /* MODULE_07_EX00_INCLUDES_ITER_HPP_ */
