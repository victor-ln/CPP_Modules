/* Copyright © 2022 Victor Nunes, Licensed under the MIT License. */

#ifndef MODULE_04_EX03_INCLUDES_ICE_HPP_
#define MODULE_04_EX03_INCLUDES_ICE_HPP_

#include <iostream>
#include <string>

#include "./AMateria.hpp"
#include "./ICharacter.hpp"

class Ice : public AMateria {
 public:
    Ice(void);
    Ice(const Ice&);
    ~Ice(void);

    Ice&        operator=(const AMateria&);
    Ice*        clone(void) const;
    void        use(const ICharacter& target) const;
};

#endif /* MODULE_04_EX03_INCLUDES_ICE_HPP_ */
