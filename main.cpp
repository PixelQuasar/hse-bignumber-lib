//
// Created by QUASARITY on 27.01.2024.
//
#include <iostream>
#include "BigNumber.h"

int main() {
    BigNumber a = BigNumber("12345.6");
    BigNumber b = BigNumber("1234.56");
    BigNumber c = a + b;
    std::cout << a << std::endl << b << std::endl << c << std::endl;

    return 0;
}
