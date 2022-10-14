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
