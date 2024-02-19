//
// Created by QUASARITY on 19.02.2024.
//
#include <iostream>

std::string strPowerOfTen(int n) {
    std::string result = "1";
    for (int i = 0; i < n; i++) {
        result += "0";
    }
    return result;
}
