//
// Created by QUASARITY on 30.01.2024.
//
#include "BigNumber.h"
#include <iostream>

BigNumber BigNumber::sub(const BigNumber& a, const BigNumber& b, bool reduceZeros) {
    BigNumber result;
    if (a.sign && !b.sign) return add(a, -b);
    if (!a.sign && b.sign) return -add(-a, b);

    if (a == b) return BigNumber(0);
    if (a.isZero()) {
        return -b;
    }
    if (b.isZero()) {
        return a;
    }

    if (a > b) result.sign = false;
    else if (a < b) {
        return -sub(b, a);
    }
    else {
        result.payload.push_back(0);
        result.sign = false;
        return result;
    }

    result.pointPosition = a.pointPosition > b.pointPosition ? a.pointPosition : b.pointPosition;
    std::string redundantMultiplier (std::abs(a.pointPosition - b.pointPosition), '0');
    redundantMultiplier.insert (0, 1, '1');
    BigNumber termA = a;
    BigNumber termB = b;
    if (termA.pointPosition > termB.pointPosition) {
        termB = BigNumber::mul(termB, BigNumber(redundantMultiplier), false);
        termB.pointPosition = termA.pointPosition;
    }
    else if (termA.pointPosition < termB.pointPosition) {
        termA = BigNumber::mul(termA, BigNumber(redundantMultiplier), false);
        termA.pointPosition = termB.pointPosition;
    }

    int completeWithZerosValue = termA.payload.size() - termB.payload.size();
    if (completeWithZerosValue < 0) {
        for (int i = 0; i < -completeWithZerosValue; i++) {
            termA.payload.push_back(0);
        };
    }
    else if (completeWithZerosValue > 0) {
        for (int i = 0; i < completeWithZerosValue; i++) {
            termB.payload.push_back(0);
        };
    }
    int carry = 0;
    for (size_t i = 0; i < termB.payload.size() || carry; i++) {
        int currentChunk = termA.payload[i] - carry - termB.payload[i];
        carry = currentChunk < 0;
        if (carry) currentChunk += base;
        result.payload.push_back(currentChunk);
    }

    while (result.payload.size() > 1 && result.payload.back() == 0) {
        result.payload.pop_back();
    }
    return reduceZeros ? result.removeZeros() : result;
}
