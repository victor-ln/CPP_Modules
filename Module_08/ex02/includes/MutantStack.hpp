/* Copyright © 2022 Victor Nunes, Licensed under the MIT License. */

#ifndef MODULE_08_EX01_INCLUDES_SPAN_HPP_
#define MODULE_08_EX01_INCLUDES_SPAN_HPP_

#include <exception>
#include <iostream>
#include <stack>

template<typename T>
class MutantStack : public std::stack<T> {
 public:
    typedef std::deque<T>                         Base;
    typedef typename Base::reverse_iterator       iterator;
    typedef typename Base::iterator               reverse_iterator;
    typedef typename Base::const_reverse_iterator const_iterator;
    typedef typename Base::const_iterator         const_reverse_iterator;

    MutantStack(void);
    explicit MutantStack(const unsigned int n);
    MutantStack(const MutantStack<T>&);
    ~MutantStack(void);

    MutantStack& operator=(const MutantStack<T>&);

    iterator           begin(void);
    iterator           end(void);
    const_iterator     cbegin(void);
    const_iterator     cend(void);

    reverse_iterator           rbegin(void);
    reverse_iterator           rend(void);
    const_reverse_iterator     crbegin(void);
    const_reverse_iterator     crend(void);
};

#include "./MutantStack.tpp"

#endif /* MODULE_08_EX01_INCLUDES_SPAN_HPP_ */
