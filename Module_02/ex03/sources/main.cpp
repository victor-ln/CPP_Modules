/* Copyright © 2022 Victor Nunes, Licensed under the MIT License. */

#include <cstdlib>
#include <iomanip>
#include <iostream>

#include "../includes/Point.hpp"

#define SPACE    " \t\n\r\f\v"
#define UNDERLINE    "__________________________________________________"
#define OVERLINE    "‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾"


static inline void    strtrim(std::string* s);
static bool            getInput(std::string message, std::string* to);

int    main(void) {
    const std::string    messages[2] = {"Point is outside the triangle", \
                                        "Point is inside the triangle"};
    const Point            a(0, 0);
    const Point            b(20.0f, 0);
    const Point            c(10.0f, 30.0f);
    float                axes[2];
    std::string            input;
    bool                result;
    int                    n;

    while (true) {
        std::cout << "Point A: (X: " << a.getXValue() << ",";
        std::cout << " Y: " << a.getYValue() << ")" << std::endl;
        std::cout << "Point B: (X: " << b.getXValue() << ",";
        std::cout << " Y: " << b.getYValue() << ")" << std::endl;
        std::cout << "Point C: (X: " << c.getXValue() << ",";
        std::cout << " Y: " << c.getYValue() << ")" << std::endl;
        n = 0;
        while (n < 2) {
            getInput("Enter " + std::string(!n ? "X" : "Y") +
                    " Axis number or Ctrl+D to exit ", &input);
            if (std::cin.eof())
                return (0);
            if (input.find_first_not_of("-0123456789.") != std::string::npos) {
                std::cout << "Invalid Input" << std::endl;
                input.clear();
                continue;
            }
            axes[n] = atof(input.c_str());
            input.clear();
            ++n;
        }
        result = bsp(a, b, c, Point(axes[0], axes[1]));
        std::cout << "Point D: (" << axes[0] << ", "
                                    << axes[1] << ")" << std::endl;
        std::cout << UNDERLINE << std::endl;
        std::cout << "          " << messages[result] << std::endl;
        std::cout << OVERLINE << std::endl;
    }
}

static bool    getInput(std::string message, std::string* to) {
    std::cout << message;
    std::cout << std::setfill('.') << std::setw(50 - message.length());
    std::cout << " :" << std::endl;
    std::cin.clear();
    std::cin.sync();
    std::getline(std::cin, *to);
    strtrim(to);
    return (!to->empty());
}

static inline void    strtrim(std::string* s) {
    s->erase(s->find_last_not_of(SPACE) + 1);
    s->erase(0, s->find_first_not_of(SPACE));
}
