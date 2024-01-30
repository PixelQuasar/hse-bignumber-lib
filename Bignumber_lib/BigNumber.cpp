//
// Created by QUASARITY on 27.01.2024 with love.
//

#include <iostream>
#include <iomanip>
#include "BigNumber.h"
#include "utils/trim.cpp"
#include "utils/completeWithZeros.cpp"

// constructor with void
BigNumber::BigNumber() {
    sign = false;
    pointPosition = 0;
}

// constructor with int
BigNumber::BigNumber(int x) {
    BigNumber fromString = BigNumber(std::to_string(x));
    *this = fromString;
}

// constructor with float
BigNumber::BigNumber(float x) {
    BigNumber fromString = BigNumber(std::to_string(x));
    *this = fromString;
}

// constructor with double
BigNumber::BigNumber(double x) {
    BigNumber fromString = BigNumber(std::to_string(x));
    *this = fromString;
}

// constructor with long long
BigNumber::BigNumber(long long x) {
    BigNumber fromString = BigNumber(std::to_string(x));
    *this = fromString;
}

// base constructor
BigNumber::BigNumber(std::vector<u_int32_t> newPayload, bool newSign, int newPointPosition) {
    payload = newPayload;
    sign = newSign;
    pointPosition = newPointPosition;
}

BigNumber::BigNumber(std::string x) {
    // trim and erase zeros
    x.erase ( x.find_last_not_of('.') + 1, std::string::npos );
    x = trim(x);

    // get sign
    if (x[0] == '-') {
        sign = true;
        x = x.substr(1, x.length() - 1);
    } else {
        sign = false;
    }

    // get point position
    pointPosition = 0;
    for (int i = 0; i < x.length(); i++) {
        if (x[i] == '.' || x[i] == ',') {
            x.erase(i, 1);
            pointPosition = i;
            break;
        }
    }

    for (int i = (int)x.length(); i > 0; i -= 9) {
        if (i < 9) {
            payload.push_back(atoi(x.substr(0, i).c_str()));
        } else {
            payload.push_back(atoi(x.substr(i - 9, 9).c_str()));
        }
    }
}

// destructor
BigNumber::~BigNumber() {
    payload.clear();
}

// utils
std::string BigNumber::toString() {
    std::string result = "";
    if (sign) result += "-";
    result += std::to_string(payload.back());
    for (int i = (int)payload.size() - 2; i >= 0; i--) {
        result += completeWithZeros(&payload[i], BigNumber::baseLen);
    }
    return result;
}

BigNumber BigNumber::removeStartZeros() {

}

// to write
std::ostream& operator<< (std::ostream& stream, const BigNumber& bigNumber) {
    if (bigNumber.sign) stream << "-";
    stream << bigNumber.payload.back();
    for (int i = (int)bigNumber.payload.size() - 2; i >= 0; i--) {
        stream <<
               std::setfill('0') <<
               std::setw(BigNumber::baseLen) <<
               bigNumber.payload[i];
    }

    return stream;
}

// to read
std::istream& operator>> (std::istream& stream, BigNumber& bigNumber) {
    std::string temp;
    stream >> temp;
    bigNumber = BigNumber(temp);
    return stream;
}

// unary minus
BigNumber operator-(const BigNumber& x) {
    BigNumber result;
    result.payload = x.payload;
    result.sign = !result.sign;
    result.payload = x.payload;
    return result;
}

// sum
BigNumber operator+(const BigNumber& a, const BigNumber& b) {
    return BigNumber::add(a, b);
};

// diff
BigNumber operator-(const BigNumber& a, const BigNumber& b) {
    return BigNumber::sub(a, b);
};

// mul
BigNumber operator*(const BigNumber& a, const BigNumber& b) {
    return BigNumber::mul(a, b);
};

// div
BigNumber operator/(const BigNumber& a, const BigNumber& b) {
    return BigNumber::div(a, b);
};


BigNumber BigNumber::operator++(int) {
    BigNumber old = *this;
    *this = add(*this, BigNumber(1));
    return old;
}

BigNumber BigNumber::operator--(int) {
    BigNumber old = *this;
    *this = sub(*this, BigNumber(1));
    return old;
}

// for BigNumber
bool operator==(const BigNumber& a, const BigNumber& b) {
    return BigNumber::compare(a, b) == 0;
};

bool operator>(const BigNumber& a, const BigNumber& b) {
    return BigNumber::compare(a, b) == -1;
};

bool operator>=(const BigNumber& a, const BigNumber& b) {
    return BigNumber::compare(a, b) != 1;
};

bool operator<(const BigNumber& a, const BigNumber& b) {
    return BigNumber::compare(a, b) == 1;
};

bool operator<=(const BigNumber& a, const BigNumber& b) {
    return BigNumber::compare(a, b) != -1;
};

bool operator!=(const BigNumber& a, const BigNumber& b) {
    return BigNumber::compare(a, b) != 0;
};

// for int
bool operator==(const BigNumber& a, const int& b) {
    // TODO: optimize pater
    return a == BigNumber(b);
};

bool operator>(const BigNumber& a, const int& b) {
    // TODO: optimize pater
    return a > BigNumber(b);
};

bool operator>=(const BigNumber& a, const int& b) {
    // TODO: optimize pater
    return a >= BigNumber(b);
};

bool operator<(const BigNumber& a, const int& b) {
    // TODO: optimize pater
    return a < BigNumber(b);
};

bool operator<=(const BigNumber& a, const int& b) {
    // TODO: optimize pater
    return a <= BigNumber(b);
};

bool operator!=(const BigNumber& a, const int& b) {
    // TODO: optimize pater
    return a != BigNumber(b);
};

BigNumber& BigNumber::operator=(const BigNumber& a) {
    payload = a.payload;
    pointPosition = a.pointPosition;
    sign = a.sign;

    return *this;
}

BigNumber& BigNumber::operator=(const int& a) {
    //TODO: optimize later
    *this = BigNumber(a);

    return *this;
}

// DEBUG METHODS: REMOVE LATER
uint32_t BigNumber::getFirstChunk() {
    return payload[0];
}

std::string BigNumber::debug() {
    std::string result = "\nPayload array:\n";
    for (uint32_t item : payload) {
        result += completeWithZeros(&item, BigNumber::baseLen) + " ";
    }
    result += "\nPoint position: " + std::to_string(pointPosition) + "\nSign: " + (sign ? "-" : "+");
    return result;
}

// private
// compare operators
int BigNumber::compare(BigNumber a, BigNumber b) {
    // a > b: -1
    // a < b: 1
    // a = b: 0
    if ((a.sign == 1 && b.sign == 0) || a.payload.size() < b.payload.size()) return 1;
    if ((a.sign == 0 && b.sign == 1) || a.payload.size() > b.payload.size()) return -1;
    for (int i = (int)a.payload.size() - 1; i >= 0; i--) {
        if (a.payload[i] < b.payload[i]) return a.sign ? -1 : 1;
        if (b.payload[i] > a.payload[i]) return a.sign ? 1 : -1;
    }
    return 0;
}

// copy
BigNumber BigNumber::copy() const {
    BigNumber newBigNumber;
    newBigNumber.payload = payload;
    newBigNumber.sign = sign;
    newBigNumber.pointPosition = pointPosition;
    return newBigNumber;
}

BigNumber BigNumber::countPi(int accuracy) {

}



//TODO: everything else