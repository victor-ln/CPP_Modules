/* Copyright © 2022 Victor Nunes, Licensed under the MIT License. */

#include <cstdlib>
#include <iostream>

#include "../includes/Array.hpp"

#define MAX_VAL     750
#define MAX_STRS    5

static void     initIntArray(Array<int>* numbers, int *nbMirror);

template<typename T>
static void    testIfIsInitialized(const Array<T>& array);

template<typename T>
static void    testInvalidAccess(const Array<T>& array);

template<typename T>
static void    testIsDeepCopying(const Array<T>& array);

template<typename T>
static bool    testIfValuesAreTheSame(const Array<T>& array, T* srcArray);


int main(void) {
    Array<int>          numbers(MAX_VAL);
    Array<std::string>  strings(MAX_STRS);

    int         *nbMirror = new int[MAX_VAL];
    std::string sMirror[MAX_STRS] = {"Hello", "World", "from", "C++", "!"};

    testIfIsInitialized(numbers);
    testIfIsInitialized(strings);
    initIntArray(&numbers, nbMirror);
    for (int i = 0; i < MAX_STRS; i++)
        strings[i] = sMirror[i];
    if (!testIfValuesAreTheSame<int>(numbers, nbMirror))
        std::cout << "didn't save the same value!!\n\n";
    if (!testIfValuesAreTheSame<std::string>(strings, sMirror))
        std::cout << "didn't save the same value!!\n\n";
    testInvalidAccess(numbers);
    testInvalidAccess(strings);
    delete [] nbMirror;
    return 0;
}

/**
 * It initializes two arrays of integers with random values
 * 
 * @param numbers The class array<int> to initialize
 * @param nbMirror An array that will be used to check 
 * that all values have been stored correctly.
 */
static void     initIntArray(Array<int>* numbers, int *nbMirror) {
    unsigned int    seed = time(NULL);
    int             value;

    for (int i = 0; i < MAX_VAL; i++) {
        value = rand_r(&seed);
        nbMirror[i] = value;
        (*numbers)[i] = value;
    }
}

template<typename T>
static void    testIfIsInitialized(const Array<T>& array) {
    std::cout << "\tTesting if is initialized by default\n\n";
    std::cout << array[0] << '\n';
    std::cout << array[array.size() - 1] << '\n';
    std::cout << '\n';
}


/**
 * It tries to access an element of the array that is out of bounds, and catches
 * the exception that is thrown
 */
template<typename T>
static void    testInvalidAccess(const Array<T>& array) {
    try {
        std::cout << array[-2] << '\n';
    } catch(const std::exception& e) {
        std::cout << e.what() << '\n';
    }
    try {
        std::cout << array[array.size()] << '\n';
    } catch(const std::exception& e) {
        std::cout << e.what() << '\n';
    }
}

/**
 * It tests if the copy constructor and assignment operator is deep copying
 */
template<typename T>
static void    testIsDeepCopying(const Array<T>& array) {
    std::cout << "\tTesting if is deep copying\n\n";
    Array<T> tmp1 = array;
    Array<T> test1(tmp1);
    std::cout << '\n';
}

/**
 * It tests if the values in the array are the same as the values in the source
 * array
 * 
 * @param array The array to test.
 * @param srcArray The source array to copy from.
 * 
 * @return If they are the same, it returns true, otherwise it returns false.
 */
template<typename T>
static bool    testIfValuesAreTheSame(const Array<T>& array, T* srcArray) {
    for (size_t i = 0; i < array.size(); i++)
        if (srcArray[i] != array[i])
            return (false);
    return (true);
}
