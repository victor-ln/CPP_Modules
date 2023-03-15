/* Copyright © 2023 Victor Nunes, Licensed under the MIT License. */

#include "../includes/RPN.hpp"

RPN::RPN(void)
    : _numbers(), _valid_characters("0123456789 +-*/") {}

RPN::RPN(RPN& src)
    :  _numbers(src._numbers), _valid_characters(src._valid_characters) {}

RPN::~RPN() {}

RPN& RPN::operator=(RPN& src) {
    _numbers = src._numbers;
    _valid_characters = src._valid_characters;
    return *this;
}

void    RPN::execute(const char* expr) {
    bool        status = true;

    for (; _is_expr(*expr) && status; expr++) {
        if (isspace(*expr)) {
            continue;
        } else if (isdigit(*expr)) {
            _numbers.push(atoi(expr++));
            if (_numbers.top() > 9) {
                std::cout << "Error: Numbers must be less than 10\n";
                return;
            }
        } else {
            status = _calculate_operation(_which_operation(*expr));
        }
    }
    if (!status) {
        std::cout << "Error: Invalid sequence of operations\n";
    } else if (*expr) {
        std::cout << "Error: Invalid characters on expression\n";
    } else {
        std::cout << "Expression results: " << _numbers.top() << '\n';
    }
}

bool    RPN::_is_expr(char ch) {
    return ch && _valid_characters.find(ch) != std::string::npos;
}

RPN::e_operations    RPN::_which_operation(char ch) {
    if (ch == '+') {
        return plus;
    } else if (ch == '-') {
        return minus;
    } else if (ch == '*') {
        return times;
    } else {
        return divide;
    }
}

bool    RPN::_calculate_operation(e_operations operation) {
    int     x, y;

    y = _pop_number();
    x = _pop_number();
    if (x == 10 || y == 10) {
        return false;
    }
    switch (operation) {
        case plus: _numbers.push(x + y); break;
        case minus: _numbers.push(x - y); break;
        case times: _numbers.push(x * y); break;
        case divide: _numbers.push(x / y); break;
    }
    return true;
}

int     RPN::_pop_number(void) {
    int     x;

    if (!_numbers.empty()) {
        x = _numbers.top();
        _numbers.pop();
        return x;
    }
    return 10;
}
