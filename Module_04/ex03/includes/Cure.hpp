/* Copyright © 2022 Victor Nunes, Licensed under the MIT License. */

#ifndef MODULE_04_EX03_INCLUDES_CURE_HPP_
#define MODULE_04_EX03_INCLUDES_CURE_HPP_

#include <iostream>
#include <string>

#include "./AMateria.hpp"
#include "./ICharacter.hpp"

class Cure : public AMateria {
 public:
    Cure(void);
    Cure(const AMateria&);
    explicit Cure(const std::string&);
    ~Cure(void);

    Cure&       operator=(const Cure&);
    Cure*       clone(void) const;
    void        use(const ICharacter& target) const;
};

#endif /* MODULE_04_EX03_INCLUDES_CURE_HPP_ */
