//
// Created by QUASARITY on 30.01.2024.
//
#include "BigNumber.h"
#include <iostream>

BigNumber BigNumber::mul(BigNumber a, BigNumber b) {
    BigNumber c = BigNumber(a.payload.size() + b.payload.size(), 0);
    c.sign = a.sign ^ b.sign;
    c.pointPosition = a.pointPosition + b.pointPosition;

    for (size_t i = 0; i<a.payload.size(); ++i) {
        for (int j = 0, carry = 0; j < (int) b.payload.size() || carry; ++j) {
            long long cur = c.payload[i + j] + a.payload[i] * 1ll * (j < (int) b.payload.size() ? b.payload[j] : 0) + carry;
            c.payload[i + j] = int(cur % base);
            carry = int(cur / base);
        }
    }

    while (c.payload.size() > 1 && c.payload.back() == 0) {
        c.payload.pop_back();
    }
    return c;
}
