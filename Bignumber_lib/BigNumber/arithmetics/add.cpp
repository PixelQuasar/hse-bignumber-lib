//
// Created by QUASARITY on 30.01.2024.
//
#include "BigNumber.h"
#include <iostream>

BigNumber BigNumber::add(const BigNumber a, const BigNumber b, bool reduceZeros) {
    // handle base cases:
    //std::cout << a << " + " << b << " = ";
    if (a.sign && !b.sign) return sub(b, -a);
    if (!a.sign && b.sign) return sub(a, -b);
    if (a.isZero()) {
        //std::cout << b << std::endl;
        return b;
    }
    if (b.isZero()) {
        //std::cout << b << std::endl;
        return a;
    }

    BigNumber result;
    result.pointPosition = a.pointPosition > b.pointPosition ? a.pointPosition : b.pointPosition;
    std::string redundantMultiplier (std::abs(a.pointPosition - b.pointPosition), '0');
    redundantMultiplier.insert (0, 1, '1');
    BigNumber termA = a, termB = b;
    if (termA.pointPosition > termB.pointPosition) {
        termB = BigNumber::mul(termB, BigNumber(redundantMultiplier), false);
        termB.pointPosition = termA.pointPosition;
    }
    else if (termA.pointPosition < termB.pointPosition) {
        termA = BigNumber::mul(termA, BigNumber(redundantMultiplier), false);
        termA.pointPosition = termB.pointPosition;
    }
    if (termA.payload.size() < termB.payload.size()) {
        while (termA.payload.size() < termB.payload.size()) termA.payload.push_back(0);
    }
    if (termA.payload.size() > termB.payload.size()) {
        while (termA.payload.size() > termB.payload.size()) termB.payload.push_back(0);
    }

    //std::cout << termA << " " << termB << std::endl;

    int carry = 0;
    for (size_t i = 0; i < std::max(termA.payload.size(), termB.payload.size()); i++) {
        uint32_t chunkSum = termA.payload[i] + termB.payload[i] + carry;
        carry = 0;
        if (chunkSum > BigNumber::base) {
            chunkSum -= BigNumber::base;
            carry = 1;
        }
        result.payload.push_back(chunkSum);
    }

    if (termA.sign) result.sign = true;

    //std::cout << result << std::endl;
    return reduceZeros ? result.removeZeros() : result;
}