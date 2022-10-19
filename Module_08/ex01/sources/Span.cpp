/* Copyright © 2022 Victor Nunes, Licensed under the MIT License. */

#include "../includes/Span.hpp"

Span::Span(void) : _array(0), _arrayLimit(0) {}

Span::Span(const unsigned int n) : _arrayLimit(n) {
    _array = new int[n]();
    _end   = Iterator(_array + _arrayLimit);
    _lastAdded  = Iterator(_array);
}

Span::Span(const Span& src) : _arrayLimit(src._arrayLimit) {
    *this = src;
}

Span::~Span(void) {
    if (_array)
        delete [] _array;
}

Span& Span::operator=(const Span& rhs) {
    if (_array) {
        delete [] _array;
        _array = 0;
    }
    const_cast<unsigned int&>(_arrayLimit) = rhs._arrayLimit;
    if (_arrayLimit) {
        _array = new int[_arrayLimit];
    }
    Iterator rhsIterator = const_cast<Span&>(rhs).begin();
    Iterator lhsIterator = begin();
    if (rhsIterator != rhs._lastAdded) {
        for (; rhsIterator != rhs._lastAdded; ++rhsIterator, ++lhsIterator)
            *lhsIterator = *rhsIterator;
    }
    _end       = Iterator(_array + _arrayLimit);
    _lastAdded = lhsIterator;
    return *this;
}

void Span::addNumber(const int nb) {
    if (_lastAdded != _end) {
        *_lastAdded = nb;
        ++_lastAdded;
        std::sort(_array, _lastAdded.operator->());
    } else {
        throw OutOfRange();
    }
}

int Span::shortestSpan(void) {
    if (_lastAdded == begin() || _lastAdded == ++(begin()))
        throw NoSpanFound();
    int diff = ~(1 << 31);

    for (Iterator st = begin(), nd = ++(begin()); nd != _lastAdded; ++st, ++nd)
        if (*nd - *st < diff)
            diff =  *nd - *st;
    return diff;
}

int Span::longestSpan(void) {
    if (_lastAdded == begin() || _lastAdded == ++(begin()))
        throw NoSpanFound();
    return *(--Iterator(_lastAdded)) - *(begin());
}

Span::Iterator::Iterator(Span::Iterator::pointer ptr) : m_ptr(ptr) {}

Span::Iterator::Iterator(void) : m_ptr(0) {}

Span::Iterator::Iterator(const Iterator& src) : m_ptr(src.m_ptr) {}

Span::Iterator::~Iterator(void) {}

Span::Iterator& Span::Iterator::operator=(const Span::Iterator& src) {
    m_ptr = src.m_ptr;
    return *this;
}

Span::Iterator Span::begin(void)  {
    return Iterator(_array);
}

Span::Iterator Span::end(void) {
    return Iterator(_lastAdded);
}

Span::Iterator::reference Span::Iterator::operator*(void) {
    return *m_ptr;
}

Span::Iterator::pointer Span::Iterator::operator->(void) {
    return m_ptr;
}

Span::Iterator&    Span::Iterator::operator++(void) {
    ++m_ptr;
    return *this;
}

Span::Iterator     Span::Iterator::operator++(int) {
    Iterator    tmp(m_ptr);
    ++m_ptr;
    return tmp;
}

Span::Iterator&    Span::Iterator::operator--(void) {
    --m_ptr;
    return *this;
}

Span::Iterator     Span::Iterator::operator--(int) {
    Iterator    tmp(m_ptr);
    --m_ptr;
    return tmp;
}

bool    Span::Iterator::operator==(const Iterator& rhs) const {
    return (m_ptr == rhs.m_ptr);
}

bool    Span::Iterator::operator!=(const Iterator& rhs) const {
    return (m_ptr != rhs.m_ptr);
}

const char *Span::OutOfRange::what(void) const throw() {
    return ("Iterator out of range. Read/Write memory access error");
}

const char *Span::NoSpanFound::what(void) const throw() {
    return ("There are no numbers to compare which is the shortest/longest");
}
