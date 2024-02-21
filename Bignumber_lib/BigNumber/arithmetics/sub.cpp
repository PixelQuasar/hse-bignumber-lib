//
// Created by QUASARITY on 30.01.2024.
//
#include "BigNumber.h"
#include <iostream>

BigNumber BigNumber::sub(const BigNumber a, const BigNumber b, bool reduceZeros) {
    //std::cout << a << " - " << b << " = ";
    BigNumber result;
    if (a.sign && !b.sign) return add(a, -b);
    if (!a.sign && b.sign) return -add(-a, b);

    if (a == b) return BigNumber(0);
    if (a.isZero()) {
        //std::cout << "SUBRES: " << b << std::endl;
        return -b;
    }
    if (b.isZero()) {
        //std::cout << "SUBRES: " << a << std::endl;
        return a;
    }

    if (a > b) result.sign = false;
    else if (a < b) {
        return -sub(b, a);
    }
    else {
        result.payload.push_back(0);
        result.sign = false;
        //std::cout << "SUBRES: " << result << std::endl;
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

    //std::cout << "\nSUB:\n" << termA << "\n" << termB << std::endl << std::endl;
    //std:: cout << termA.debug() << termB.debug() << std::endl;
    //return result.removeZeros();

    int completeWithZerosValue = termA.payload.size() - termB.payload.size();
    //std::cout << "hi!!! " << completeWithZerosValue << std::endl;
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
    //std::cout << "hi" << std::endl;
    //std::cout << termA << std::endl << termB << std::endl;
    //std::cout << termA.debug() << std::endl << termB.debug() << std::endl;
    int carry = 0;
    for (size_t i = 0; i < termB.payload.size() || carry; i++) {
        //std::cout << "CONDITION " << (i < termB.payload.size()) << " " << carry << std::endl;
        int currentChunk = termA.payload[i] - carry - termB.payload[i];
        //std::cout << currentChunk << std::endl;
        carry = currentChunk < 0;
        if (carry) currentChunk += base;
        result.payload.push_back(currentChunk);
        //std::cout << "CHUNK: " << currentChunk << " (" << termA.payload[i] << " " << termB.payload[i] << ")" << std::endl;
        //std::cout << "CARRY: " << carry << std::endl;
    }
    //std::cout << result.debug() << std::endl;

    while (result.payload.size() > 1 && result.payload.back() == 0) {
        result.payload.pop_back();
    }
    //std::cout << "SUBRES: " << result << std::endl;
    //std::cout << result << std::endl;
    return reduceZeros ? result.removeZeros() : result;

//    for (int i = 0; i < termA.payload.size(); i++) {
//        u_int32_t diff = BigNumber::base + termA.payload[i] - termB.payload[i] - carry;
//        carry = 0;
//        if (diff > BigNumber::base) {
//            diff -= BigNumber::base;
//        }
//        else {
//            carry = 1;
//        }
//        std::cout << diff << std::endl;
//        result.payload.push_back(diff);
//    }
}