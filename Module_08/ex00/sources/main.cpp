/* Copyright © 2022 Victor Nunes, Licensed under the MIT License. */

#include <deque>
#include <iostream>
#include <list>
#include <vector>

#include "../includes/easyfind.hpp"

int main(void) {
    std::deque<int>     deque;
    std::list<int>      list;
    std::vector<int>    vector;
    unsigned int        seed = static_cast<unsigned int>(time(NULL));
    int                 value = rand_r(&seed) % 20;

    for (int i = 0; i < 10; i++) {
        vector.push_back(i);
        list.push_back(i);
        deque.push_back(i);
    }
    std::cout << "Value to find:\t" << value << '\n';
    try {
        std::cout << "vector:\t" << *(easyFind(vector, value)) << std::endl;
    } catch(const std::exception& e) {
        std::cout << e.what() << '\n';
    }
    try {
        std::cout << "list:\t" << *(easyFind(list, value)) << std::endl;
    } catch(const std::exception& e) {
        std::cout << e.what() << '\n';
    }
    try {
        std::cout << "deque:\t" << *(easyFind(deque, value)) << std::endl;
    } catch(const std::exception& e) {
        std::cout << e.what() << '\n';
    }
    return 0;
}
