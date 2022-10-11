/* Copyright © 2022 Victor Nunes, Licensed under the MIT License. */

#include "../includes/scalarConverter.hpp"

static e_types impossibleConversion(const std::string& s, scalarTypes *t);
static e_types getActualType(const std::string& s, scalarTypes *t);
static e_types nbConversion(const std::string& s, scalarTypes *t);

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
    if (s.find("nan") != std::string::npos || \
        s.find("inf") != std::string::npos)
        return (impossibleConversion(s, t));
    if (s.find_first_of("0123456789") != std::string::npos)
        return (nbConversion(s, t));
    if (s.length() > 1)
        return (invalid);
    t->character = s.at(0);
    return (character);
}

static e_types impossibleConversion(const std::string& s, scalarTypes *t) {
    t->isImpossibleNb = true;
    if (s.find("nanf") != std::string::npos || \
        s.find("inff") != std::string::npos) {
        t->floating = static_cast<float>(atof(s.c_str()));
        return (floating);
    }
    t->lFloating = atof(s.c_str());
    return (lFloating);
}

static e_types nbConversion(const std::string& s, scalarTypes *t) {
    if (s.find_first_not_of("0123456789.f") != std::string::npos) {
        return (invalid);
    } else if (s.find_first_of(".") != std::string::npos) {
        if (s.find_first_of("f") != std::string::npos) {
            t->floating = static_cast<float>(atof(s.c_str()));
            return (floating);
        }
        t->lFloating = atof(s.c_str());
        return (lFloating);
    }
    t->integer = atoi(s.c_str());
    return (integer);
}
