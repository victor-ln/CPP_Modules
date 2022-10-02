/* Copyright © 2022 Victor Nunes, Licensed under the MIT License. */

#include <iostream>

int main(void) {
    std::string     str("HI THIS IS BRAIN");
    std::string*    strP = &str;
    std::string&    strR = str;

    std::cout << &str << std::endl;
    std::cout << strP << std::endl;
    std::cout << &strR << std::endl;

    std::cout << str << std::endl;
    std::cout << *strP << std::endl;
    std::cout << strR << std::endl;

    return (0);
}
