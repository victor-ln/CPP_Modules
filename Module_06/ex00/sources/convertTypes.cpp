/* Copyright © 2022 Victor Nunes, Licensed under the MIT License. */

#include "../includes/scalarConverter.hpp"

static e_types impossibleConversion(const std::string& str, scalarTypes *alltypes);
static e_types getActualType(const std::string& str, scalarTypes *alltypes);
static e_types nbConversion(const std::string& str, scalarTypes *alltypes);

void    convertTypes(scalarTypes *allTypes, const char *argv) {
    switch (getActualType(argv, allTypes)) {
        case character:
            convertToOtherTypes<char>(allTypes->character, allTypes);
            break;
        case integer:
            convertToOtherTypes<int>(allTypes->integer, allTypes);
            break;
        case floating:
            convertToOtherTypes<float>(allTypes->floating, allTypes);
            break;
        case lFloating:
            convertToOtherTypes<double>(allTypes->lFloating, allTypes);
            break;
        default:
            std::cout << "Invalid type\n";
            exit(0);
    }
}

static e_types getActualType(const std::string& str, scalarTypes *alltypes) {
    if (str.find("nan") != std::string::npos || \
        str.find("inf") != std::string::npos)
        return (impossibleConversion(str, alltypes));
    if (str.find_first_of("0123456789") != std::string::npos)
        return (nbConversion(str, alltypes));
    if (str.length() > 1)
        return (invalid);
    alltypes->character = str.at(0);
    return (character);
}

static e_types impossibleConversion(const std::string& str, scalarTypes *alltypes) {
    alltypes->isImpossibleNb = true;
    if (str.find("nanf") != std::string::npos || \
        str.find("inff") != std::string::npos) {
        alltypes->floating = (float)atof(str.c_str());
        return (floating);
    }
    alltypes->lFloating = atof(str.c_str());
    return (lFloating);
}

static e_types nbConversion(const std::string& str, scalarTypes *alltypes) {
    if (str.find_first_not_of("0123456789.f") != std::string::npos) {
        return (invalid);
    } else if (str.find_first_of(".") != std::string::npos) {
        if (str.find_first_of("f") != std::string::npos) {
            alltypes->floating = (float)atof(str.c_str());
            return (floating);
        }
        alltypes->lFloating = atof(str.c_str());
        return (lFloating);
    }
    alltypes->integer = atoi(str.c_str());
    return (integer);
}
