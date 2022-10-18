/* Copyright © 2022 Victor Nunes, Licensed under the MIT License. */

#ifndef MODULE_08_EX01_INCLUDES_SPAN_HPP_
#define MODULE_08_EX01_INCLUDES_SPAN_HPP_

#include <bits/stdc++.h>

#include <algorithm>
#include <exception>
#include <iostream>

typedef int* pointer;

class Span {
 public:
    Span(void);
    explicit Span(const unsigned int n);
    Span(const Span&);
    ~Span(void);

  /*                   Assignment operator                    */
    Span&           operator=(const Span&);

    void            addNumber(int);
    int             shortestSpan(void);
    int             longestSpan(void);

    class Iterator {
     public:
        typedef std::forward_iterator_tag     iterator_category;
        typedef std::ptrdiff_t                difference_type;
        typedef int                           value_type;
        typedef int*                          pointer;
        typedef int&                          reference;

        Iterator(void);
        Iterator(const Iterator&);
        explicit Iterator(pointer ptr);
        ~Iterator(void);

      /*                   Assignment operator                    */
        Iterator&          operator=(const Iterator&);

      /*                   Accessors operators                    */
        reference          operator*(void);
        pointer            operator->(void);

      /*                   Increment operators                    */
        Iterator&          operator++(void); /* Prefix */
        Iterator           operator++(int);  /* Posfix */

      /*                   Decrement operators                    */
        Iterator&          operator--(void); /* Prefix */
        Iterator           operator--(int);  /* Posfix */

      /*                   Relational operators                   */
        bool               operator==(const Iterator&) const;
        bool               operator!=(const Iterator&) const;

     private:
        pointer m_ptr;
    };

    Iterator        begin(void);
    Iterator        end(void);

    /**
     * Inserts the elements in the range [first, ..., last] 
     * into the span, starting at pos
     * 
     * @param pos the position in the array to insert the new elements
     * @param first The first element in the range of elements to be inserted.
     * @param last the last element in the array
     */
    template<typename _InputIterator>
    void insert(Span::Iterator pos, _InputIterator first, _InputIterator last) {
        bool  fromLast = pos == _lastAdded;

        for (; first != last && pos != _end; ++first, ++pos)
            *pos = *first;
        if (fromLast)
            _lastAdded = pos;
        std::sort(_array, _lastAdded.operator->());
        if (first != last)
            throw OutOfRange();
    }

    /**
     * Iterate over an array of any type, and call a function on each element.
     * 
     * @param first The address of the first element in the array.
     * @param size The number of elements to iterate over.
     * @param func The function to call on each element.
     */
    template<typename function>
    void iter(Iterator first, const unsigned int size, function func) {
        Iterator    lastIt(_lastAdded.operator->() + size);

        for (; first != lastIt && first != _end; ++first)
            func(*first);
        if (_lastAdded.operator->() < first.operator->())
            _lastAdded = first;
        std::sort(_array, _lastAdded.operator->());
        if (first != lastIt)
            throw OutOfRange();
    }

 private:
    int                   *_array;
    Iterator              _end;
    Iterator              _lastAdded;
    const unsigned int    _arrayLimit;

    class OutOfRange : public std::exception {
        const char *what(void) const throw();
    };
    class NoSpanFound : public std::exception {
        const char *what(void) const throw();
    };
};

#endif /* MODULE_08_EX01_INCLUDES_SPAN_HPP_ */
