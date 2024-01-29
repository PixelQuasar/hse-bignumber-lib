//
// Created by QUASARITY on 27.01.2024.
//
#include <iostream>
#include "BigNumber.h"

int main()
{
    BigNumber x = BigNumber("10000000000000000000000000000000");
    BigNumber y = BigNumber("1");
    std::cout << (-x  + (-y)) << std::endl;

    return 0;
}
