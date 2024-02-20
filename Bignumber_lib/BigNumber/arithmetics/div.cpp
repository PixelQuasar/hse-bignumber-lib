//
// Created by QUASARITY on 30.01.2024.
//
#include "BigNumber.h"
#include <iostream>
#include <vector>

//BigNumber BigNumber::div(const BigNumber a, const BigNumber b, bool reduceZeros) {
//    BigNumber numberA = a, numberB = b;
//    if(numberA < numberB){
//        numberA = BigNumber("0");
//        return numberA;
//    }
//    if(numberA == numberB){
//        numberA = BigNumber("1");
//        return numberA;
//    }
//    int i, lgcat = 0, cc;
//    int n = numberA.payload.size(), m = b.payload.size();
//    std::vector<uint32_t> cat(n, 0);
//    BigNumber t;
//    for (i = n - 1; t * BigNumber(base) + BigNumber(std::to_string(numberA.payload[i])) < numberB;i--){
//        t *= BigNumber(base);
//        t += BigNumber(std::to_string(a.payload[i]));
//    }
//    for (; i >= 0; i--){
//        t = t * BigNumber(base) + BigNumber(std::to_string(numberA.payload[i]));
//        for (int cc = base - 1; BigNumber(cc) * numberB > t; cc--);
//        t -= BigNumber(cc) * numberB;
//        cat[lgcat++] = cc;
//    }
//
//    numberA.payload.resize(cat.size());
//    for (size_t i = 0; i < lgcat; i++) {
//        numberA.payload[i] = cat[lgcat - i - 1];
//    }
//    numberA.payload.resize(lgcat);
//    return numberA;
//}

BigNumber BigNumber::div(const BigNumber a, const BigNumber b, bool reduceZeros) {
    //std::cout << a << " / " << b << " = ";
    if (b == 1)  {
        //std::cout << "I AM DIVISION RESULT! " << a << std::endl;
        return a;
    }
    if (b == -1) {
        //std::cout << "I AM DIVISION RESULT! " << -a << std::endl;
        return -a;
    }

    BigNumber numberA = a;

    BigNumber low = BigNumber(0);
    BigNumber high = numberA.abs();
    BigNumber mid = BigNumber(0);

    BigNumber quotient = BigNumber(0);

    size_t limitIndex = 0;
    while (low <= high && limitIndex < 10000) {

        std::cout << "DIFF: " << high - low << std::endl;
        mid = low + (high - low) * "0.5"_bign;

        std::cout << "LOW: " << low << std::endl;
        std::cout << "MID: " << mid << std::endl;
        std::cout << "TOP: " << high << std::endl << std::endl;

        if (mid.pointPosition == 1) mid -= "0.5"_bign;
        //std::cout << mid << std::endl;
        BigNumber attempt = mid * b;
        if (attempt.abs() == numberA.abs()) {
            quotient = mid;
            break;
        } else if (attempt.abs() > numberA.abs()) {
            high = mid - BigNumber(1);
        } else {
            quotient = mid;
            low = mid + BigNumber(1);
        }
        limitIndex += 1;
    }
    if ((a < 0 && b < 0 || a > 0 && b > 0)) {
        //std::cout << "I AM DIVISION RESULT! " << quotient << std::endl;
        return quotient;
    }
    else {
        //std::cout << "I AM DIVISION RESULT! " << quotient << std::endl;
        return -quotient;
    }
}

//BigInteger& BigInteger::operator/=(SelfRefBigInt other) {  BigInteger quotient;
//    if (sign == Sign::zero) {
//        return *this;
//    }  if (sign == other.sign) {
//        quotient.sign = Sign::positive;
//    } else {
//        quotient.sign = Sign::negative;
//    }
//    quotient.number.resize(number.size());  BigInteger current;
//    for (size_t i = number.size(); i > 0; i--) {
//        current.shift();
//        current.number[0] = number[i - 1];
//        current.remove_zeros();
//        if (current.number[current.number.size() - 1] != 0) {
//            current.sign = Sign::positive;
//        } else {
//            current.sign = Sign::zero;
//        }
//        int incomplete_quotient = 0;
//        int left = 0;
//        int right = kSystem;
//        while (left <= right) {
//            int median = (left + right) / 2;
//            if (other.abs() * median <= current) {
//                incomplete_quotient = median;
//                left = median + 1;
//            } else {
//                right = median - 1;
//            }
//        }    quotient.number[i - 1] = incomplete_quotient;
//        current -= incomplete_quotient * other.abs();
//    }
//    quotient.remove_zeros();  *this = quotient;
//    return *this;
//}