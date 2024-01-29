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

BigNumber::BigNumber(std::string x) {
    // trim and erase zeros
    x.erase ( x.find_last_not_of('0') + 1, std::string::npos );
    x.erase ( x.find_last_not_of('.') + 1, std::string::npos );
    x = trim(x);

    std::cout << x << std::endl;

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

// utils
std::string BigNumber::toString() {

}

BigNumber BigNumber::removeStartZeros() {

}

static BigNumber BigNumber::buildEmpty() {
    BigNumber result = BigNumber();
    result.payload.pop_back();
    return result;
}

// to write
std::ostream& operator<< (std::ostream& stream, const BigNumber& bigNumber) {
    stream << bigNumber.payload.back();
    for (int i = (int)bigNumber.payload.size() - 2; i >= 0; --i) {
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
    return BigNumber::compare(a, b) == 0;
};

// is bigger than
bool operator>(const BigNumber& a, const BigNumber& b) {
    return BigNumber::compare(a, b) == 1;
};

// is bigger or equals
bool operator>=(const BigNumber& a, const BigNumber& b) {
    return BigNumber::compare(a, b) != -1;
};

// is lesser than
bool operator<(const BigNumber& a, const BigNumber& b) {
    return BigNumber::compare(a, b) == -1;
};

// is lesser or equals
bool operator<=(const BigNumber& a, const BigNumber& b) {
    return BigNumber::compare(a, b) != 1;
};

// is not equals
bool operator!=(const BigNumber& a, const BigNumber& b) {
    return BigNumber::compare(a, b) != 0;
};

BigNumber& BigNumber::operator=(const BigNumber& bigNumber) {
    payload = bigNumber.payload;
    pointPosition = bigNumber.pointPosition;
    sign = bigNumber.sign;

    return *this;
}

// DEBUG METHODS: REMOVE LATER
uint32_t BigNumber::getFirstChunk() {
    return payload[0];
}

std::string BigNumber::debug() {
    std::string result = "Payload array: ";
    for (uint32_t item : payload) {
        result += std::to_string(item) + " ";
    }
    result += "\nPoint position: " + std::to_string(pointPosition) + "\nSign: " + (sign ? "-" : "+");
    return result;

}

// private
// binary operators
BigNumber BigNumber::sum(BigNumber a, BigNumber b) {
    BigNumber result = BigNumber::buildEmpty();
    int reminder = 0;
    for (size_t i = 0; i < std::max(a.payload.size(), b.payload.size()); i++) {
        uint32_t chunkSum = a.payload[i] + b.payload[i];
        if (reminder == 1) chunkSum++;
        if (chunkSum > BigNumber::base) {
            chunkSum -= BigNumber::base;
            reminder = 1;
        }
        result.payload.push_back(chunkSum);
    }
    return result;
}

BigNumber BigNumber::dif(BigNumber a, BigNumber b) {
    int carry = 0;
    BigNumber result = a;
    for (size_t i = 0; i < b.payload.size() || carry; ++i) {
        result.payload[i] -= carry + (i < b.payload.size() ? b.payload[i] : 0);
        carry = result.payload[i] < 0;
        if (carry) result.payload[i] += base;
    }
    while (result.payload.size() > 1 && result.payload.back() == 0) {
        result.payload.pop_back();
    }
    return result;
}

BigNumber BigNumber::mul(BigNumber a, BigNumber b) {

}

BigNumber BigNumber::div(BigNumber a, BigNumber b) {

}

// compare operators
int BigNumber::compare(BigNumber a, BigNumber b) {
    // a > b: -1
    // a < b: 1
    // a = b: 0
    if ((a.sign == 1 && b.sign == 0) || a.payload.size() < b.payload.size()) return 1;
    if ((a.sign == 0 && b.sign == 1) || a.payload.size() > b.payload.size()) return -1;
    for (size_t i = a.payload.size() - 1; i <= 0; i--) {
        if (a < b) return 1;
        if (b > a) return -1;
    }
    return 0;
}

BigNumber BigNumber::countPi(int accuracy) {

}

//TODO: everything else