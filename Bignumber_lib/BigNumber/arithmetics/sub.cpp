#include "BigNumber.h"

BigNumber BigNumber::sub(BigNumber a, BigNumber b) {
    int carry = 0;
    BigNumber result;

    if (a.sign && !b.sign) {
        return add(a, -b);
    }

    if (a > b) {
        result.sign = false;
    }
    else if (a < b) {
        std::swap(a, b);
        result.sign = true;
    }
    else {
        result.payload.push_back(0);
        result.sign = false;
        return result;
    }

    for (int i = 0; i <= a.payload.size() - b.payload.size() + 1; i++) {
        b.payload.push_back(0);
    }

    for (int i = 0; i < a.payload.size(); i++) {
        u_int32_t diff = BigNumber::base + a.payload[i] - b.payload[i] - carry;
        carry = 0;
        if (diff > BigNumber::base) {
            diff -= BigNumber::base;
        }
        else {
            carry = 1;
        }
        result.payload.push_back(diff);
    }

    result.pointPosition = 0;
    return result;
}