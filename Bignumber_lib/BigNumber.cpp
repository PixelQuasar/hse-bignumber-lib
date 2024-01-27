//
// Created by QUASARITY on 27.01.2024 with love.
//

#include <iomanip>

#include "BigNumber.h"

// constructor with void
BigNumber::BigNumber() {
    sign = false;
    pointPosition = 0;
    payload.push_back(0);
}

// constructor with int
BigNumber::BigNumber(int x) {
    sign = false;
    pointPosition = 0;
    payload.push_back(x);
}

// constructor with float
BigNumber::BigNumber(float x) {
    sign = false;
    pointPosition = 0;
    //TODO: float parsing implementation
}

// constructor with double
BigNumber::BigNumber(double x) {
    sign = false;
    pointPosition = 0;
    //TODO: double parsing implementation
}

// constructor with long long
BigNumber::BigNumber(long long x) {
    sign = false;
    pointPosition = 0;
    //TODO: long-long parsing implementation
}

// destructor
BigNumber::~BigNumber() {
    payload.clear();
}

// << overloading for cout
std::ostream& operator<< (std::ostream& stream, const BigNumber& bigNumber) {
    stream <<  bigNumber.payload.back();
    for (int i=(int)bigNumber.payload.size() - 2; i >= 0; --i) {
        stream <<
            std::setfill('0') <<
            std::setw(BigNumber::baseLen) <<
            bigNumber.payload[i];
    }

    return stream;
}

// DEBUG METHORDS: REMOVE LATER
int BigNumber::getFirstChunk() {
    return payload[0];
}

//TODO: everything else
