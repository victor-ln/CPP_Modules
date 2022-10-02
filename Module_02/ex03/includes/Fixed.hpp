/* Copyright © 2022 Victor Nunes, Licensed under the MIT License. */

#ifndef MODULE_02_EX03_INCLUDES_FIXED_HPP_
#define MODULE_02_EX03_INCLUDES_FIXED_HPP_

#include <iostream>

class Fixed {
 public:
    Fixed(void);
    ~Fixed(void);
    explicit Fixed(int);
    explicit Fixed(float);
    Fixed(const Fixed&);

    Fixed&   operator=(const Fixed&);
    bool     operator==(const Fixed&) const;
    bool     operator!=(const Fixed&) const;
    bool     operator>(const Fixed&) const;
    bool     operator<(const Fixed&) const;
    bool     operator<=(const Fixed&) const;
    bool     operator>=(const Fixed&) const;
    Fixed    operator+(const Fixed&) const;
    Fixed    operator-(const Fixed&) const;
    Fixed    operator*(const Fixed&) const;
    Fixed    operator/(const Fixed&) const;
    Fixed&   operator++(void);
    Fixed    operator++(int);
    Fixed&   operator--(void);
    Fixed    operator--(int);

    static const Fixed&    max(const Fixed&, const Fixed&);
    static const Fixed&    min(const Fixed&, const Fixed&);
    static Fixed&          max(Fixed&, Fixed&);
    static Fixed&          min(Fixed&, Fixed&);

    int        getRawBits(void) const;
    void       setRawBits(int const raw);
    float      toFloat(void) const;
    int        toInt(void) const;

 private:
    int                 _fixedNbValue;
    static const int    _fractionalBitNb;
};

std::ostream&    operator<<(std::ostream&, const Fixed&);

#endif /* MODULE_02_EX03_INCLUDES_FIXED_HPP_ */
