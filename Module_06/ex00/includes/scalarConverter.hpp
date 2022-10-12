/* Copyright © 2022 Victor Nunes, Licensed under the MIT License. */

#ifndef MODULE_06_EX00_INCLUDES_SCALARCONVERTER_HPP_
#define MODULE_06_EX00_INCLUDES_SCALARCONVERTER_HPP_

#include <cstdlib>
#include <cstring>
#include <iostream>
#include <iomanip>
#include <limits>
#include <string>

enum    e_types {
    character,
    integer,
    floating,
    lFloating,
    invalid
};

struct scalarTypes {
    char      character;
    int       integer;
    float     floating;
    double    lFloating;
    bool      isImpossibleNb;
    bool      isFloating;
    size_t    fltPrecision;
    size_t    dblPrecision;
};

template<typename T>
void convertToOtherTypes(T value, scalarTypes *types) {
    types->character = static_cast<char>(value);
    types->integer = static_cast<int>(value);
    types->floating = static_cast<float>(value);
    types->lFloating = static_cast<double>(value);
}

void convertTypes(scalarTypes *allTypes, const char *argv);

#endif /* MODULE_06_EX00_INCLUDES_SCALARCONVERTER_HPP_ */
