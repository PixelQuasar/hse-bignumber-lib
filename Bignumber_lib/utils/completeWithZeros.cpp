//
// Created by QUASARITY on 29.01.2024.
//
#include <iostream>
std::string completeWithZeros (uint32_t* a, size_t len) {
    std::string result = std::to_string(*a);
    size_t zerosToAdd = len - result.length();

    if (zerosToAdd > 0) {
        result.insert(0, zerosToAdd, '0');
    }

    return result;
}
