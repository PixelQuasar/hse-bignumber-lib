//
// Created by QUASARITY on 27.01.2024.
//

#include "BigNumber.h"
#include <iostream>
#include <chrono>

int main() {
    std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
    std::string pi = "3.1415926535897932384626433832795028841971693993751058209749445923078164062862089986280348253421170679";

    BigNumber countedPi = BigNumber::countPi(100);
    std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();

    return !(pi == BigNumber::toString(countedPi));
}