//
// Created by QUASARITY on 30.01.2024.
//
#include "BigNumber.h"
#include <iostream>

BigNumber BigNumber::sub(const BigNumber a, const BigNumber b) {
    int carry = 0;
    BigNumber result;

    if (a.sign && !b.sign) {
        return add(a, -b);
    }
    if (!a.sign && b.sign) {
        return -add(-a, b);
    }

    if (a > b) {
        result.sign = false;
    }
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
        termB *= BigNumber(redundantMultiplier);
        termB.pointPosition = termA.pointPosition;
    }
    else if (termA.pointPosition < termB.pointPosition) {
        termA *= BigNumber(redundantMultiplier);
        termA.pointPosition = termB.pointPosition;
    }

    std::cout << termA << " " << termB << std::endl;

    for (int i = 0; i <= termA.payload.size() - termB.payload.size() + 1; i++) {
        termB.payload.push_back(0);
    }

    for (int i = 0; i < termA.payload.size(); i++) {
        u_int32_t diff = BigNumber::base + termA.payload[i] - termB.payload[i] - carry;
        carry = 0;
        if (diff > BigNumber::base) {
            diff -= BigNumber::base;
        }
        else {
            carry = 1;
        }
        result.payload.push_back(diff);
    }

    return result;
}