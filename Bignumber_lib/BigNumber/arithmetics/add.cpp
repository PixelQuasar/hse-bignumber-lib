//
// Created by QUASARITY on 30.01.2024.
//
#include "BigNumber.h"

BigNumber BigNumber::add(const BigNumber a, const BigNumber b) {
    if (a.sign && !b.sign) {
        return sub(b, a);
    }

    if (b.sign && !a.sign) {
        return sub(a, b);
    }

    BigNumber result;
    result.pointPosition = 0;
    int carry = 0;
    for (size_t i = 0; i < std::max(a.payload.size(), b.payload.size()); i++) {
        uint32_t chunkSum = a.payload[i] + b.payload[i] + carry;
        if (chunkSum > BigNumber::base) {
            chunkSum -= BigNumber::base;
            carry = 1;
        }
        result.payload.push_back(chunkSum);
    }

    if (a.sign) result.sign = true;
    result.pointPosition = 0;
    return result;
}