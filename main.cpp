//
// Created by QUASARITY on 27.01.2024.
//
#include <iostream>
#include "BigNumber.h"

int main()
{
    BigNumber x = BigNumber(45.45);
    BigNumber y = x;
    std::cout << x.debug() << std::endl << y.debug() << std::endl;

    return 0;
}