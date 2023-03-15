/* Copyright © 2023 Victor Nunes, Licensed under the MIT License. */

#ifndef MODULE_09_EX01_INCLUDES_RPN_HPP_
#define MODULE_09_EX01_INCLUDES_RPN_HPP_

#include <stack>
#include <iostream>
#include <string>
#include <cstdlib>

class RPN {
 public:
    RPN(void);
    RPN(RPN&);
    ~RPN();

    RPN&            operator=(RPN&);

    void            execute(const char*);
 private:
    enum e_operations {
        plus, minus, times, divide
    };

    std::stack<int>     _numbers;
    std::string         _valid_characters;

    bool            _is_expr(char);
    e_operations    _which_operation(char);
    bool            _calculate_operation(e_operations);
    int             _pop_number(void);
};  /* RPN class */

#endif /* MODULE_09_EX01_INCLUDES_RPN_HPP_ */
