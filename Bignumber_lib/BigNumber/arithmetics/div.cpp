//
// Created by QUASARITY on 30.01.2024.
//
#include "BigNumber.h"
#include <iostream>

BigNumber BigNumber::div(BigNumber a, BigNumber b) {
    BigNumber q(0);

    while (a >= b) {
        a = sub(a, b);
        q = add(q, BigNumber(1));
    };

    return q;
}
