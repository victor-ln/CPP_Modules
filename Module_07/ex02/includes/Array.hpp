/* Copyright © 2022 Victor Nunes, Licensed under the MIT License. */

#ifndef MODULE_07_EX01_INCLUDES_ITER_HPP_
#define MODULE_07_EX01_INCLUDES_ITER_HPP_

#include <iostream>

template<typename T>
class Array {
 public:
    Array(void);
    Array(unsigned int n);
    Array(const Array&);
    ~Array(void);

    Array&           operator=(const Array&);
    T&               operator[](const unsigned int) const;

    unsigned int      size(void) const;

 private:
    unsigned int     _arrayLength;
    T               *_array;
};

#include "./Array.tpp"

#endif /* MODULE_07_EX01_INCLUDES_ITER_HPP_ */
