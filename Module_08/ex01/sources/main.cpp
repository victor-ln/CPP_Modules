/* Copyright © 2022 Victor Nunes, Licensed under the MIT License. */

#include <iostream>

#include "../includes/Span.hpp"

typedef        Span::Iterator iterator;

static void    subjectTest(void);
static void    putRand(int& nb);
static void    printSpan(Span& span);
static void    testExceptions(void);

#define MAX_VALUE 500

int main(void) {
    Span                sp(MAX_VALUE);

    std::cout << "\n\tSpan:\n";
    sp.iter(sp.begin(), 30, putRand);
    printSpan(sp);
    std::cout << "\nshortestSpan\t: " << sp.shortestSpan() << '\n';
    std::cout << "\nlongestSpan\t: " << sp.longestSpan() << '\n';
    sp.iter(sp.end(), 20, putRand);
    printSpan(sp);
    std::cout << "\nshortestSpan\t: " << sp.shortestSpan() << '\n';
    std::cout << "\nlongestSpan\t: " << sp.longestSpan() << '\n';
    sp.iter(sp.end(), 450, putRand);
    printSpan(sp);
    std::cout << "\nshortestSpan\t: " << sp.shortestSpan() << '\n';
    std::cout << "\nlongestSpan\t: " << sp.longestSpan() << '\n';
    subjectTest();
    testExceptions();
    return 0;
}

static void    putRand(int& nb) {
    static unsigned int seed = static_cast<unsigned int>(time(NULL));
    nb = rand_r(&seed);
}

static void  printSpan(Span& span) {
    std::cout << '\n';
    for (iterator it = span.begin(), end = span.end(); it != end; ++it)
        std::cout << *it << ", ";
    std::cout << '\n';
}

static void    subjectTest(void) {
    Span sp = Span(5);

    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);
    std::cout << "\n\tSubject test:\n";
    std::cout << sp.shortestSpan() << std::endl;
    std::cout << sp.longestSpan() << std::endl;
}

static void    testExceptions(void) {
    Span    sp;

    try {
        std::cout << "\n\t[Test 00]:"
                    << " Empty Span adding number\n";
        sp.addNumber(19);
    } catch(const std::exception& e) {
        std::cout << e.what() << '\n';
    }
    try {
        std::cout << "\n\t[Test 01]:"
                    << " Empty Span getting shortest Span\n";
        sp.shortestSpan();
    } catch(const std::exception& e) {
        std::cout << e.what() << '\n';
    }
    try {
        std::cout << "\n\t[Test 02]:"
                    << " Empty Span getting longest Span\n";
        sp.longestSpan();
    } catch(const std::exception& e) {
        std::cout << e.what() << '\n';
    }
    sp = Span(1);
    sp.addNumber(10);
    try {
        std::cout << "\n\t[Test 03]:"
                    << " having a number and trying to get the shortest Span\n";
        sp.shortestSpan();
    } catch(const std::exception& e) {
        std::cout << e.what() << '\n';
    }
    try {
        std::cout << "\n\t[Test 04]:"
                    << " having a number and trying to get the longest Span\n";
        sp.longestSpan();
    } catch(const std::exception& e) {
        std::cout << e.what() << '\n';
    }
}
