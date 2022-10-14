/* Copyright © 2022 Victor Nunes, Licensed under the MIT License. */

#include <cstdlib>
#include <iostream>

#include "../includes/Array.hpp"

#define MAX_VAL     750
#define MAX_STRS    5

void     initIntArray(Array<int>* numbers, int *nbMirror);

template<typename T>
void    testIfIsInitialized(const Array<T>& array);

template<typename T>
void    testInvalidAccess(const Array<T>& array);

template<typename T>
void    testIsDeepCopying(const Array<T>& array);

template<typename T>
bool    testIfValuesAreTheSame(const Array<T>& array, T* srcArray);

template<typename T>
void    testEmptyArray(T value);
