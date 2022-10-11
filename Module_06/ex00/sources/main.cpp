/* Copyright © 2022 Victor Nunes, Licensed under the MIT License. */

#include "../includes/scalarConverter.hpp"

void getFloatsPrecisions(scalarTypes *allTypes, const char *argv);
void printIntegerTypes(const scalarTypes& allTypes);
void printFloatTypes(const scalarTypes& allTypes);

int main(int argc, char const *argv[]) {
    if (argc != 2) {
        std::cout << "No parameters passed.\n";
        std::cout << "Execute './program <param>' without brackets '<>'\n";
        std::cout << "The param will be converted to all primitive types\n";
        std::cout << "Param examples:\n0\na\nnan\n-inf\n";
        return (0);
    }
    scalarTypes     allTypes;

    allTypes.isImpossibleNb = false;
    convertTypes(&allTypes, argv[1]);
    getFloatsPrecisions(&allTypes, argv[1]);
    printIntegerTypes(allTypes);
    printFloatTypes(allTypes);
    return (0);
}

void getFloatsPrecisions(scalarTypes *allTypes, const char *argv) {
    const char *point = strchr(argv, '.');

    allTypes->dblPrecision = strlen(argv) + 2;
    allTypes->fltPrecision = allTypes->dblPrecision;
    allTypes->isFloating = point != NULL;
    if (allTypes->isFloating) {
        size_t  decimalDigits = strlen(point);

        allTypes->dblPrecision = point - argv;
        allTypes->fltPrecision = allTypes->dblPrecision;
        if (decimalDigits > std::numeric_limits<double>::digits10)
            allTypes->dblPrecision += std::numeric_limits<double>::digits10;
        else
            allTypes->dblPrecision += decimalDigits;
        if (decimalDigits > std::numeric_limits<float>::digits10)
            allTypes->fltPrecision += std::numeric_limits<float>::digits10;
        else
            allTypes->fltPrecision += decimalDigits;
    }
}

void    printIntegerTypes(const scalarTypes& allTypes) {
    if (allTypes.isImpossibleNb) {
        std::cout << "char:\t" << "impossible\n";
        std::cout << "int:\t" << "impossible\n";
    } else {
        std::cout << "char:\t";
        if (isprint(allTypes.character))
            std::cout << "'" << allTypes.character << "'\n";
        else
            std::cout << "Non displayable\n";
        std::cout << "int:\t" << allTypes.integer << '\n';
    }
}

void    printFloatTypes(const scalarTypes& allTypes) {
    std::cout << "float:\t";
    std::cout << std::setprecision(allTypes.fltPrecision) << allTypes.floating;
    if (!allTypes.isFloating && !allTypes.isImpossibleNb)
        std::cout << ".0";
    std::cout << "f\n";
    std::cout << "double:\t";
    std::cout << std::setprecision(allTypes.dblPrecision) << allTypes.lFloating;
    if (!allTypes.isFloating && !allTypes.isImpossibleNb)
        std::cout << ".0";
    std::cout << '\n';
}
