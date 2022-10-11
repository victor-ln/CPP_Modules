/* Copyright © 2022 Victor Nunes, Licensed under the MIT License. */

#ifndef MODULE_06_EX01_INCLUDES_DATA_HPP_
#define MODULE_06_EX01_INCLUDES_DATA_HPP_

#include <stdint.h>

struct Data {
    long   value;
};

uintptr_t   serialize(Data* ptr);
Data*       deserialize(uintptr_t raw);

#endif /* MODULE_06_EX01_INCLUDES_DATA_HPP_ */
