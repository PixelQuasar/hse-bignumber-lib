//
// Created by QUASARITY on 30.01.2024.
//
#include "BigNumber.h"
#include <iostream>

BigNumber BigNumber::add(BigNumber a, BigNumber b) {
    if (a.sign && !b.sign) {
        return sub(b, -a);
    }

    if (b.sign && !a.sign) {
        return sub(a, b);
    }

    BigNumber result;
    result.pointPosition = a.pointPosition > b.pointPosition ? a.pointPosition : b.pointPosition;
    std::string redundantMultiplier (abs(a.pointPosition - b.pointPosition), '0');
    redundantMultiplier.insert (0, 1, '1');
    if (a.pointPosition > b.pointPosition) {
        b *= BigNumber(redundantMultiplier);
    }
    else if (a.pointPosition < b.pointPosition) {
        a *= BigNumber(redundantMultiplier);
    }

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
    return result;
}