/* Copyright © 2022 Victor Nunes, Licensed under the MIT License. */

#ifndef MODULE_04_EX03_INCLUDES_DUMP_HPP_
#define MODULE_04_EX03_INCLUDES_DUMP_HPP_

#include "./AMateria.hpp"

struct Node {
    AMateria    *data;
    Node        *next;
};

class Dump {
 public:
    Dump(void);
    Dump(const Dump&);
    ~Dump(void);

    Dump    operator=(const Dump&);
    void    push(AMateria *);

 private:
    Node    *_head;
};

#endif /* MODULE_04_EX03_INCLUDES_DUMP_HPP_ */
