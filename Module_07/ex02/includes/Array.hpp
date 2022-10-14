/* Copyright © 2022 Victor Nunes, Licensed under the MIT License. */

#ifndef MODULE_07_EX02_INCLUDES_ARRAY_HPP_
#define MODULE_07_EX02_INCLUDES_ARRAY_HPP_

template<typename T>
class Array {
 public:
    Array(void);
    explicit Array(unsigned int n);
    Array(const Array&);
    ~Array(void);

    Array&           operator=(const Array&);
    T&               operator[](const unsigned int) const;

    unsigned int      size(void) const;

 private:
    unsigned int     _arrayLength;
    T               *_array;

    class InvalidAccess : public std::exception {
      const char *what(void) const throw();
    };
};

#include "./Array.tpp"

#endif /* MODULE_07_EX02_INCLUDES_ARRAY_HPP_ */
