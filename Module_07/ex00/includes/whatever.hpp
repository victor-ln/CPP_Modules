/* Copyright © 2022 Victor Nunes, Licensed under the MIT License. */

#ifndef MODULE_07_EX00_INCLUDES_WHATEVER_HPP_
#define MODULE_07_EX00_INCLUDES_WHATEVER_HPP_

template<typename T>
void    swap(T& a, T& b) {
    T   c = a;
    a = b;
    b = c;
}

template<typename T>
const T&    max(const T& a, const T& b) {
    return (a > b ? a : b);
}

template<typename T>
const T&    min(const T& a, const T& b) {
    return (a < b ? a : b);
}

#endif /* MODULE_07_EX00_INCLUDES_WHATEVER_HPP_ */
