/* Copyright © 2022 Victor Nunes, Licensed under the MIT License. */

#include "./easyfind.hpp"

template<typename T>
typename T::iterator easyFind(T& a, const int nb) {
    typename T::iterator it = std::find(a.begin(), a.end(), nb);

    if (it != a.end())
        return (it);
    throw ::NotFound();
}

const char *NotFound::what(void) const throw() {
    return ("Value not found");
}
