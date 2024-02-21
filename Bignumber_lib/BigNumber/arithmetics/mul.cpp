//
// Created by QUASARITY on 30.01.2024.
//
#include "BigNumber.h"
#include <iostream>

BigNumber BigNumber::mul(const BigNumber a, const BigNumber b, bool reduceZeros) {
    BigNumber result = BigNumber(a.payload.size() + b.payload.size(), 0);
    result.sign = a.sign ^ b.sign;
    result.pointPosition = a.pointPosition + b.pointPosition;

    for (size_t i = 0; i < a.payload.size(); ++i) {
        for (int j = 0, carry = 0; j < (int) b.payload.size() || carry; j++) {
            long long cur = result.payload[i + j] + a.payload[i] * 1ll * (j < (int) b.payload.size() ? b.payload[j] : 0) + carry;
            result.payload[i + j] = int(cur % base);
            carry = int(cur / base);
        }
    }

    while (result.payload.size() > 1 && result.payload.back() == 0) {
        result.payload.pop_back();
    }
    return reduceZeros ? result.removeZeros() : result;
}
