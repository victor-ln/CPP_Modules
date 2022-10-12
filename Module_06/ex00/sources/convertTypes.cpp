/* Copyright © 2022 Victor Nunes, Licensed under the MIT License. */

#include "../includes/scalarConverter.hpp"

static e_types impossibleConversion(const std::string& s, scalarTypes *t);
static e_types getActualType(const std::string& s, scalarTypes *t);
static e_types nbConversion(const std::string& s, scalarTypes *t);

const std::size_t   nFound = std::string::npos;

void    convertTypes(scalarTypes *t, const char *argv) {
    switch (getActualType(argv, t)) {
        case character:
            convertToOtherTypes<char>(t->character, t);
            break;
        case integer:
            convertToOtherTypes<int>(t->integer, t);
            break;
        case floating:
            convertToOtherTypes<float>(t->floating, t);
            break;
        case lFloating:
            convertToOtherTypes<double>(t->lFloating, t);
            break;
        default:
            std::cout << "Invalid type\n";
            exit(0);
    }
}

static e_types getActualType(const std::string& s, scalarTypes *t) {
    if (s.find("nan") != nFound || s.find("inf") != nFound)
        return (impossibleConversion(s, t));
    if (s.find_first_of("0123456789") != nFound)
        return (nbConversion(s, t));
    if (s.length() > 1)
        return (invalid);
    t->character = s.at(0);
    return (character);
}

static e_types impossibleConversion(const std::string& s, scalarTypes *t) {
    t->isImpossibleNb = true;
    if (s == "nan" || s == "inf") {
        t->lFloating = atof(s.c_str());
        return (lFloating);
    }
    if (s == "nanf" || s == "inff") {
        t->floating = static_cast<float>(atof(s.c_str()));
        return (floating);
    }
    return (invalid);
}

static e_types nbConversion(const std::string& s, scalarTypes *t) {
    if (s.find_first_not_of("-0123456789.f") != nFound)
        return (invalid);
    if (s.find_last_of('-') > s.find_first_of("0123456789") && \
        s.find_last_of('-') != nFound)
        return (invalid);
    if (s.find_first_of(".") != nFound) {
        if (s.find_first_of("f") != nFound) {
            t->floating = static_cast<float>(atof(s.c_str()));
            return (floating);
        }
        t->lFloating = atof(s.c_str());
        return (lFloating);
    }
    t->integer = atoi(s.c_str());
    return (integer);
}
