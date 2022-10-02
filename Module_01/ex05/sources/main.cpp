/* Copyright © 2022 Victor Nunes, Licensed under the MIT License. */

#include "../includes/Harl.hpp"

int main(void) {
    Harl    harl;

    harl.complain("INFO");
    harl.complain("DEBUG");
    harl.complain("WARNING");
    harl.complain("ERROR");
    harl.complain("FAIL");
    return (0);
}
