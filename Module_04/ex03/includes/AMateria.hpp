/* Copyright © 2022 Victor Nunes, Licensed under the MIT License. */

#ifndef MODULE_04_EX03_INCLUDES_AMATERIA_HPP_
#define MODULE_04_EX03_INCLUDES_AMATERIA_HPP_

#include <iostream>
#include <string>

#include "./ICharacter.hpp"

class AMateria {
 public:
    AMateria(void);
    AMateria(const AMateria&);
    explicit AMateria(const std::string& type);
    virtual ~AMateria(void);

    AMateria&          operator=(const AMateria&);
    const std::string& getType(void) const;
    virtual AMateria*  clone(void) const = 0;
    virtual void       use(const ICharacter& target) const;

 protected:
    std::string     _type;
};

#endif /* MODULE_04_EX03_INCLUDES_AMATERIA_HPP_ */
