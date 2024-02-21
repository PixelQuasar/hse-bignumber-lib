//
// Created by QUASARITY on 27.01.2024.
//
#include <iostream>
#include <chrono>
#include "BigNumber.h"

int main() {
    std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();

    BigNumber pi = BigNumber::countPi(3);
    std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
    std::cout << "TEST: " << pi << std::endl;

    std::cout << "Time difference (sec) = " <<  (std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count()) /1000000.0  <<std::endl;
    return 0;
}
