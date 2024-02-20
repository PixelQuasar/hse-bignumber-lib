//
// Created by QUASARITY on 27.01.2024.
//
#include <iostream>
#include "BigNumber.h"

int main() {
    BigNumber a = BigNumber("1.00");
    BigNumber b = BigNumber("1.123");
    std::cout << (a == b) << std::endl;
//    std::cout << a + b << std::endl; // 6 + 3 = 9
//    std::cout << (-a) + b << std::endl; // -6 + 3 = -3
//    std::cout << a + (-b) << std::endl; // 6 - 3 = 3
//    std::cout << (-a) + (-b) << std::endl; // -6 + -3 = -9
//    std::cout << a - b << std::endl; // 6 - 3 = 3
//    std::cout << b - a << std::endl; // 3 - 6 = -3
//    std::cout << (-a) - b << std::endl; // -6 - 3 = -9
//    std::cout << a - (-b) << std::endl; // 6 - -3 = 9
//    BigNumber c = a / b;
    //BigNumber c = a / b;
    //std::cout << a << std::endl << b << std::endl << c << std::endl;

    return 0;
}
