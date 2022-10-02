/* Copyright © 2022 Victor Nunes, Licensed under the MIT License. */

#ifndef MODULE_02_EX01_INCLUDES_FIXED_HPP_
#define MODULE_02_EX01_INCLUDES_FIXED_HPP_

#include <iostream>
#include <string>

class Fixed {
 public:
    Fixed(void);
    ~Fixed(void);
    explicit Fixed(int);
    explicit Fixed(float);
    explicit Fixed(const Fixed&);

    Fixed&    operator=(const Fixed&);
    int       getRawBits(void) const;
    void      setRawBits(int const raw);
    float     toFloat(void) const;
    int       toInt(void) const;

 private:
    int                 _fixedNbValue;
    static const int    _fractionalBitNb;
};

std::ostream&    operator<<(std::ostream&, const Fixed&);

#endif /* MODULE_02_EX01_INCLUDES_FIXED_HPP_ */
