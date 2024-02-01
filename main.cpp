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

    for (BigNumber i = -10; i <= 10; i+=(BigNumber(-1))) {
        std::cout << i << std::endl;
    }

    return 0;
}
