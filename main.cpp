//
// Created by QUASARITY on 27.01.2024.
//
#include <iostream>
#include "BigNumber.h"

int main()
{
    BigNumber x = BigNumber("   -123.456   ");
    std::cout << x.debug() << std::endl;

    return 0;
}