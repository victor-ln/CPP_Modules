/* Copyright © 2022 Victor Nunes, Licensed under the MIT License. */

#include "./Array.hpp"

template <typename T>
Array<T>::Array(void) : _arrayLength(0), _array(0) {
}

template <typename T>
/**
 * Creates an array of n elements initialized by default.
 * 
 * @param n the length of the array
 */
Array<T>::Array(unsigned int n) : _arrayLength(n) {
    this->_array = new T[n]();
}

template <typename T>
Array<T>::Array(const Array& src) {
    *this = src;
}

template <typename T>
Array<T>::~Array(void) {
    delete [] this->_array;
    this->_arrayLength = 0;
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

/**
 * If the index is out of bounds, throw an exception,
 * otherwise return the value at the index.
 * 
 * @return A reference to the element at the given index.
 */
template <typename T>
T& Array<T>::operator[](const unsigned int idx) const {
    if (idx >= this->_arrayLength)
        throw InvalidAccess();
    return *(this->_array + idx);
}

/**
 * It returns the number of elements in the array.
 * 
 * @return _arrayLength
 */
template <typename T>
unsigned int Array<T>::size(void) const {
    return (this->_arrayLength);
}

template <typename T>
const char *Array<T>::InvalidAccess::what(void) const throw() {
    return ("Exception: Invalid index. Read/Write memory access error");
}
