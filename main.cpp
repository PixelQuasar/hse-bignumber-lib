//
// Created by QUASARITY on 27.01.2024.
//
#include <iostream>
#include "BigNumber.h"

int main() {
    BigNumber x = BigNumber("123412121234123400.003000000000");
    std::cout << x.removeZeros() << std::endl;
    //std::cout << x << std::endl;
    //x.removeZeros();

    return 0;
}
