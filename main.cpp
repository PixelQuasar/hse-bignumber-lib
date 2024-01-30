//
// Created by QUASARITY on 27.01.2024.
//
#include <iostream>
#include "BigNumber.h"

int main()
{
    BigNumber x = BigNumber("10000000000000000000000000000000");
    BigNumber y = BigNumber("1");
    std::cout << (-y + x) << std::endl;

    for (BigNumber i = 0; i < 10; i++) {
        std::cout << i << std::endl;
    }

    return 0;
}
