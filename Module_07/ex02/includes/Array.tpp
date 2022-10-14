/* Copyright © 2022 Victor Nunes, Licensed under the MIT License. */

#include "../includes/Array.hpp"

template <typename T>
Array<T>::Array(void) : _arrayLength(0) {
}

template <typename T>
Array<T>::Array(unsigned int n) : _arrayLength(n) {
    this->_array = new T[n];
}

template <typename T>
Array<T>::Array(const Array& src) {
    *this = src;
}

template <typename T>
Array<T>::~Array(void) {
    delete [] this->_array;
    this->_array = 0;
}

template <typename T>
Array<T>& Array<T>::operator=(const Array& rhs) {
    if (this->_array)
        delete [] this->_array;
    this->_array = new T[rhs._arrayLength];
    for (unsigned int i = 0; i < rhs._arrayLength; i++)
        this->_array[i] = rhs._array[i];
    this->_arrayLength = rhs._arrayLength;
    return (*this);
}

template <typename T>
T&   Array<T>::operator[](const unsigned int idx) const {
    /** TODO: throw exception
    if (idx >= this->_arrayLength)
        throw 
     */
    return *(this->_array + idx);
}

template <typename T>
unsigned int      Array<T>::size(void) const {
    return (this->_arrayLength);
}
