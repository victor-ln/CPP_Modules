/* Copyright © 2022 Victor Nunes, Licensed under the MIT License. */

#ifndef MODULE_08_EX00_INCLUDES_EASYFIND_HPP_
#define MODULE_08_EX00_INCLUDES_EASYFIND_HPP_

#include <algorithm>
#include <exception>
#include <iostream>

class NotFound : public std::exception {
    const char *what(void) const throw();
};

template<typename T>
typename T::iterator easyFind(T& a, int nb);

#include "./easyfind.tpp"

#endif /* MODULE_08_EX00_INCLUDES_EASYFIND_HPP_ */

