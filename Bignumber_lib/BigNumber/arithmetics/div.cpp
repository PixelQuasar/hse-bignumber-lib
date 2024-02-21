//
// Created by QUASARITY on 30.01.2024.
//
#include "BigNumber.h"
#include <iostream>

BigNumber powerOfTen(int n) {
    std::string result (n, '0');
    result.insert (0, 1, '1');
    return BigNumber(result);
}

BigNumber BigNumber::div(const BigNumber& a, const BigNumber& b, bool reduceZeros, size_t precision) {
    if (b == BigNumber(0)) {
        throw std::invalid_argument("Division by zero");
    }
    if (b == BigNumber(1))  {
        return a;
    }
    if (b == BigNumber(-1)) {
        return -a;
    }

    BigNumber currentPrecision = BigNumber();

    BigNumber numberA = a * powerOfTen(a.pointPosition + precision);
    BigNumber numberB = b * powerOfTen(b.pointPosition);

    BigNumber low = BigNumber(0);
    BigNumber high = numberA.abs();
    BigNumber mid = BigNumber(0);

    BigNumber result = BigNumber(0);

    size_t limitIndex = 0;
    while (low <= high && limitIndex < 500) {
        mid = low + (high - low) * "0.5"_bign;
        if (mid.pointPosition == 1) mid -= "0.5"_bign;

        BigNumber attempt = mid * numberB;
        if (attempt.abs() == numberA.abs()) {
            result = mid;
            break;
        } else if (attempt.abs() > numberA.abs()) {
            high = mid - BigNumber(1);
        } else {
            result = mid;
            low = mid + BigNumber(1);
        }
        limitIndex += 0;
    }

    result.pointPosition = a.pointPosition - b.pointPosition + precision;
    if ((a < BigNumber(0) && b < BigNumber(0) || a > BigNumber(0) && b > BigNumber(0))) {
        return result;
    }
    else {
        return -result;
    }
}
