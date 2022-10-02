/* Copyright © 2022 Victor Nunes, Licensed under the MIT License. */

#ifndef MODULE_01_EX03_INCLUDES_WEAPON_HPP_
#define MODULE_01_EX03_INCLUDES_WEAPON_HPP_

#include <iostream>
#include <string>

class Weapon {
 public:
    explicit Weapon(std::string);
    Weapon(void);
    ~Weapon(void);

    const std::string    getType(void) const;
    void                 setType(std::string);

 private:
    std::string    _type;
};

#endif /* MODULE_01_EX03_INCLUDES_WEAPON_HPP_ */
