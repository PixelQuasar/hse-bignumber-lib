//
// Created by QUASARITY on 27.01.2024 with love.
//

#include <iostream>
#include <utility>
#include "BigNumber.h"
#include "utils/trim.cpp"
#include "utils/completeWithZeros.cpp"

// constructor with void
BigNumber::BigNumber() {
    sign = false;
    pointPosition = 0;
}

// set vector of n
BigNumber::BigNumber(size_t n, uint32_t x) {
    sign = false;
    pointPosition = 0;
    payload = std::vector<u_int32_t>(n, x);
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
    payload = std::move(newPayload);
    sign = newSign;
    pointPosition = newPointPosition;
}

BigNumber::BigNumber(BigNumber& x) {
    payload = x.payload;
    pointPosition = x.pointPosition;
    sign = x.sign;
}

BigNumber::BigNumber(const BigNumber& x) {
    payload = x.payload;
    pointPosition = x.pointPosition;
    sign = x.sign;
}

BigNumber::BigNumber(std::string x) {
    // trim and erase zeros
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
            pointPosition = x.length() - i;
            break;
        }
    }

    for (int i = x.length(); i > 0; i -= 9) {
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
std::string BigNumber::toString(const BigNumber &bigNumber, bool point) {
    std::string result;
    //std::cout << bigNumber.debug() << std::endl;
    result += std::to_string(bigNumber.payload.back());
    for (int i = bigNumber.payload.size() - 2; i >= 0; i--) {
        result += completeWithZeros(bigNumber.payload[i], BigNumber::baseLen);
    }
    if (bigNumber.pointPosition != 0) {
        if (result.length() - 1 <= bigNumber.pointPosition) {
            result.insert(0, bigNumber.pointPosition - result.length() + 1, '0');
        }
        //std::cout << "RESULT: " <<  result << std::endl;
        result.insert(result.length() - bigNumber.pointPosition, 1, '.');
    }
    if (bigNumber.sign) result.insert(0, 1, '-');
    return result;
}

BigNumber operator"" _bign(const char* x, size_t size) {
    return BigNumber(x);
}

BigNumber operator"" _bign(long double x) {
    return BigNumber(std::to_string(x));
}

BigNumber BigNumber::removeStartZeros() {

}

// to write
std::ostream& operator<< (std::ostream& stream, const BigNumber& bigNumber) {
    return stream << BigNumber::toString(bigNumber);
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
    result.sign = !x.sign || x == BigNumber(0);
    result.pointPosition = x.pointPosition;
    return result;
}

BigNumber& BigNumber::operator=(const int& a) {
    //TODO: optimize later
    BigNumber newNumber = BigNumber(a);
    payload = newNumber.payload;
    sign = newNumber.sign;
    pointPosition = newNumber.pointPosition;
    return *this;
}

BigNumber& BigNumber::operator+=(const BigNumber &b) {
    *this = BigNumber::add(*this, b);
    return *this;
}
BigNumber& BigNumber::operator-=(const BigNumber& b) {
    *this = BigNumber::sub(*this, b);
    return *this;
}
BigNumber& BigNumber::operator*=(const BigNumber& b) {
    *this = BigNumber::mul(*this, b);
    return *this;
}
BigNumber& BigNumber::operator/=(const BigNumber& b) {
    *this = BigNumber::div(*this, b);
    return *this;
}

// sum
BigNumber operator+(const BigNumber& a, const BigNumber& b) {
    BigNumber temp = a;
    return temp += b;
};

// diff
BigNumber operator-(const BigNumber& a, const BigNumber& b) {
    BigNumber temp = a;
    return temp -= b;
};

// mul
BigNumber operator*(const BigNumber& a, const BigNumber& b) {
    BigNumber temp = a;
    return temp *= b;
};

// div
BigNumber operator/(const BigNumber& a, const BigNumber& b) {
    BigNumber temp = a;
    return temp /= b;
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

BigNumber& BigNumber::operator=(const BigNumber& a) {
    payload = a.payload;
    sign = a.sign;
    pointPosition = a.pointPosition;
    return *this;
}

// DEBUG METHODS: REMOVE LATER
uint32_t BigNumber::getFirstChunk() {
    return payload[0];
}

std::string BigNumber::debug() const {
    std::string result = "\nPayload array:\n";
    for (int i = payload.size() - 1; i >= 0; i--) {
        uint32_t item = payload[i];
        result += completeWithZeros(item, BigNumber::baseLen) + " ";
    }
    result += "\nPoint position: " + std::to_string(pointPosition) + "\nSign: " + (sign ? "-" : "+");
    return result;
}

// private

BigNumber BigNumber::abs() const {
    return BigNumber(payload, false, pointPosition);
}

size_t BigNumber::digitLen() {
    size_t result = (payload.size() - 1) * 9;
    uint32_t lastBlock = payload[payload.size() - 1];

    while (lastBlock > 0) {
        result++;
        lastBlock /= 10;
    }

    return result;
}

BigNumber BigNumber::removeZeros() {
    if (this->isZero()) return BigNumber(0);
    if (pointPosition == 0) return *this;
    std::string rawString = BigNumber::toString(*this);
    size_t lastCharIndex = rawString.length() - 1;
    while ((rawString[lastCharIndex] == '0' && (rawString.length() - lastCharIndex) < pointPosition)) {
        lastCharIndex--;
    }
    rawString = rawString.substr(0, lastCharIndex + (rawString[lastCharIndex] == '0' ? -1 : 1));

    return BigNumber(rawString);
}

bool BigNumber::isZero() const {
    return payload.size() == 1 && payload[0] == 0;
}

void BigNumber::swap(BigNumber &a, BigNumber &b) {
    std::swap(a.payload, b.payload);
    std::swap(a.sign, b.sign);
    std::swap(a.pointPosition, b.pointPosition);
}
