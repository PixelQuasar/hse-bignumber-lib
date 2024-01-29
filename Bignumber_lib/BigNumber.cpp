//
// Created by QUASARITY on 27.01.2024 with love.
//

#include <iostream>
#include <iomanip>
#include "utils/trim.cpp"

#include "BigNumber.h"

// constructor with void
BigNumber::BigNumber() {
    sign = false;
    pointPosition = 0;
    payload.push_back(0);
}

// constructor with int
BigNumber::BigNumber(int x) {
    sign = x < 0;
    pointPosition = 0;
    payload.push_back(x);
}

// constructor with float
BigNumber::BigNumber(float x) {
    BigNumber fromString = BigNumber(std::to_string(x));
    payload = fromString.payload;
    pointPosition = fromString.pointPosition;
    sign = fromString.sign;
}

// constructor with double
BigNumber::BigNumber(double x) {
    BigNumber fromString = BigNumber(std::to_string(x));
    payload = fromString.payload;
    pointPosition = fromString.pointPosition;
    sign = fromString.sign;
}

// constructor with long long
BigNumber::BigNumber(long long x) {
    BigNumber fromString = BigNumber(std::to_string(x));
    payload = fromString.payload;
    pointPosition = fromString.pointPosition;
    sign = fromString.sign;
}

BigNumber::BigNumber(std::string x) {
    // trim
    x = trim(x);

    // get sign
    if (x[0] == '-') {
        sign = 1;
        x = x.substr(1, x.length() - 1);
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

// << overloading for cout
std::ostream& operator<< (std::ostream& stream, const BigNumber& bigNumber) {
    stream << bigNumber.payload.back();
    for (int i = (int) bigNumber.payload.size() - 2; i >= 0; --i) {
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
    std::cout << temp << std::endl;
    bigNumber = BigNumber(temp);
    return stream;
}
// sum
BigNumber operator+(const BigNumber& a, const BigNumber& b) {

};

// diff
BigNumber operator-(const BigNumber& a, const BigNumber& b) {

};

// mul
BigNumber operator*(const BigNumber& a, const BigNumber& b) {

};

// div
BigNumber operator/(const BigNumber& a, const BigNumber& b) {

};

// increment
BigNumber operator++(const BigNumber& a) {

};

// decrement
BigNumber operator--(const BigNumber& a) {

};

// is equals
bool operator==(const BigNumber& a, const BigNumber& b) {

};

// is bigger than
bool operator>(const BigNumber& a, const BigNumber& b) {

};

// is bigger or equals
bool operator>=(const BigNumber& a, const BigNumber& b) {

};

// is lesser than
bool operator<(const BigNumber& a, const BigNumber& b) {

};

// is lesser or equals
bool operator<=(const BigNumber& a, const BigNumber& b) {

};

// is not equals
bool operator!=(const BigNumber& a, const BigNumber& b) {

};

BigNumber& BigNumber::operator=(const BigNumber& bigNumber) {
    payload = bigNumber.payload;
    pointPosition = bigNumber.pointPosition;
    sign = bigNumber.sign;

    return *this;
}

// DEBUG METHODS: REMOVE LATER
int BigNumber::getFirstChunk() {
    return payload[0];
}

std::string BigNumber::debug() {
    std::string result = "Payload array: ";
    for (int item : payload) {
        result += std::to_string(item) + " ";
    }
    result += "\nPoint position: " + std::to_string(pointPosition) + "\nSign: " + (sign ? "-" : "+");
    return result;

}

// utils
std::string BigNumber::toString() {

}

BigNumber BigNumber::removeStartZeros() {

}

//TODO: everything else