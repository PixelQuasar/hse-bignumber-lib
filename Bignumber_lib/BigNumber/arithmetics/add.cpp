//
// Created by QUASARITY on 30.01.2024.
//
#include "BigNumber.h"
#include <iostream>

BigNumber BigNumber::add(const BigNumber a, const BigNumber b) {
    if (a.sign && !b.sign) {
        return sub(b, -a);
    }

    if (b.sign && !a.sign) {
        return sub(a, b);
    }

    BigNumber result;
    result.pointPosition = a.pointPosition > b.pointPosition ? a.pointPosition : b.pointPosition;
    std::string redundantMultiplier (std::abs(a.pointPosition - b.pointPosition), '0');
    redundantMultiplier.insert (0, 1, '1');
    BigNumber termA = a, termB = b;
    if (termA.pointPosition > termB.pointPosition) {
        termB *= BigNumber(redundantMultiplier);
    }
    else if (termA.pointPosition < termB.pointPosition) {
        termA *= BigNumber(redundantMultiplier);
    }

    int carry = 0;
    for (size_t i = 0; i < std::max(termA.payload.size(), termB.payload.size()); i++) {
        uint32_t chunkSum = termA.payload[i] + termB.payload[i] + carry;
        if (chunkSum > BigNumber::base) {
            chunkSum -= BigNumber::base;
            carry = 1;
        }
        result.payload.push_back(chunkSum);
    }

    if (termA.sign) result.sign = true;
    return result;
}