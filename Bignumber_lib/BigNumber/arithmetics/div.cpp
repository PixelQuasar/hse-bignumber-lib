//
// Created by QUASARITY on 30.01.2024.
//
#include "BigNumber.h"
#include <iostream>
#include <vector>

BigNumber powerOfTen(int n) {
    std::string result (n, '0');
    result.insert (0, 1, '1');
    return BigNumber(result);
}

BigNumber BigNumber::div(const BigNumber a, const BigNumber b, bool reduceZeros, size_t precision) {
    //std::cout << a << " / " << b << " = ";
    if (b == 1)  {
        return a;
    }
    if (b == -1) {
        return -a;
    }


    BigNumber currentPrecision = BigNumber();

    BigNumber numberA = a * powerOfTen(a.pointPosition + precision);
    BigNumber numberB = b * powerOfTen(b.pointPosition);

    BigNumber low = BigNumber(0);
    BigNumber high = numberA.abs();
    BigNumber mid = BigNumber(0);

    BigNumber quotient = BigNumber(0);

    size_t limitIndex = 0;
    while (low < high) {
        //std::cout << "DIFF: " << high << " - " << low << " = " << high - low << std::endl;
        mid = low + (high - low) * "0.5"_bign;
        if (mid.pointPosition == 1) mid -= "0.5"_bign;

//        std::cout << "LOW: " << low << std::endl;
//        std::cout << "MID: " << mid << std::endl;
//        std::cout << "TOP: " << high << std::endl << std::endl;


        //std::cout << mid << std::endl;
        BigNumber attempt = mid * numberB;
        if (attempt.abs() == numberA.abs()) {
            quotient = mid;
            break;
        } else if (attempt.abs() > numberA.abs()) {
            high = mid - BigNumber(1);
        } else {
            quotient = mid;
            low = mid + BigNumber(1);
            //std::cout << "LOW SUM: " << mid << " + 1 = " << low << std::endl;
        }
        limitIndex += 0;
    }

    quotient.pointPosition = a.pointPosition + b.pointPosition + precision;
    if ((a < 0 && b < 0 || a > 0 && b > 0)) {
        //std::cout << "I AM DIVISION RESULT! " << quotient << std::endl;
        return quotient;
    }
    else {
        //std::cout << "I AM DIVISION RESULT! " << quotient << std::endl;
        return -quotient;
    }
}
