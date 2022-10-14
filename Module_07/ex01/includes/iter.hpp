/* Copyright © 2022 Victor Nunes, Licensed under the MIT License. */

#ifndef MODULE_07_EX01_INCLUDES_ITER_HPP_
#define MODULE_07_EX01_INCLUDES_ITER_HPP_

#include <iostream>

/**
 * Iterate over an array of any type, and call a function on each element.
 * 
 * @param address The address of the first element in the array.
 * @param end The number of elements to iterate over.
 * @param func The function to call on each element.
 */
template<typename T, typename function>
void iter(T *address, size_t end, function func) {
    for (size_t i = 0; i < end; i++) {
        func(*address);
        ++address;
    }
}

#endif /* MODULE_07_EX01_INCLUDES_ITER_HPP_ */
