//
// Created by QUASARITY on 21.02.2024.
//
#include <iostream>
#include "BigNumber.h"

int BigNumber::compare(const BigNumber& a, const BigNumber& b) {
    // a > b: -1
    // a < b: 1
    // a = b: 0
    BigNumber tempA = a, tempB = b;
    if (tempA.pointPosition != tempB.pointPosition) {
        std::string redundantMultiplier (std::abs(tempA.pointPosition - tempB.pointPosition), '0');
        redundantMultiplier.insert (0, 1, '1');
        if (tempA.pointPosition < tempB.pointPosition) {
            tempA = BigNumber::mul(tempA, BigNumber(redundantMultiplier), false);
            tempA.pointPosition = b.pointPosition;
        }
        else {
            tempB = BigNumber::mul(tempB, BigNumber(redundantMultiplier), false);
            tempB.pointPosition = tempA.pointPosition;
        }
    }
    if (tempA.payload.size() < tempB.payload.size()) {
        while (tempA.payload.size() < tempB.payload.size()) tempA.payload.push_back(0);
    }
    if (tempA.payload.size() > tempB.payload.size()) {
        while (tempA.payload.size() > tempB.payload.size()) tempB.payload.push_back(0);
    }
    if ((tempA.sign == 1 && tempB.sign == 0) || tempA.payload.size() < tempB.payload.size()) return 1;
    if ((tempA.sign == 0 && tempB.sign == 1) || tempA.payload.size() > tempB.payload.size()) return -1;
    for (int i = tempA.payload.size() - 1; i >= 0; i--) {
        if (tempA.payload[i] < tempB.payload[i]) return tempA.sign ? -1 : 1;
        if (tempA.payload[i] > tempB.payload[i]) return tempA.sign ? 1 : -1;
    }
    return 0;
}
