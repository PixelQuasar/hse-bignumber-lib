//
// Created by QUASARITY on 27.01.2024 with love.
//

#ifndef DEMO_LIB_BIGNUMBER_H
#define DEMO_LIB_BIGNUMBER_H

#include <vector>

class BigNumber {
    static const int base = 1e9;
    static const int baseLen = 9;
    int pointPosition;
    bool sign;
    std::vector<uint32_t> payload;

public:
        // constructors and destructors
        BigNumber();
        BigNumber(size_t n, uint32_t x);
        BigNumber(int x);
        BigNumber(double x);
        BigNumber(float x);
        BigNumber(long long x);
        BigNumber(std::string x);
        BigNumber(std::vector<u_int32_t> newPayload, bool newSign, int newPointPosition);
        ~BigNumber();

        friend std::ostream& operator<< (std::ostream& stream, const BigNumber& bigNumber);
        friend std::istream& operator>> (std::istream& stream, BigNumber& bigNumber);

        // binary
        friend BigNumber operator+(const BigNumber& a, const BigNumber& b);
        friend BigNumber operator-(const BigNumber& a, const BigNumber& b);
        friend BigNumber operator*(const BigNumber& a, const BigNumber& b);
        friend BigNumber operator/(const BigNumber& a, const BigNumber& b);

        friend bool operator==(const BigNumber& a, const int& b);
        friend bool operator>(const BigNumber& a, const int& b);
        friend bool operator>=(const BigNumber& a, const int& b);
        friend bool operator<(const BigNumber& a, const int& b);
        friend bool operator<=(const BigNumber& a, const int& b);
        friend bool operator!=(const BigNumber& a, const int& b);

        friend bool operator==(const BigNumber& a, const BigNumber& b);
        friend bool operator>(const BigNumber& a, const BigNumber& b);
        friend bool operator>=(const BigNumber& a, const BigNumber& b);
        friend bool operator<(const BigNumber& a, const BigNumber& b);
        friend bool operator<=(const BigNumber& a, const BigNumber& b);
        friend bool operator!=(const BigNumber& a, const BigNumber& b);

        // unary
        friend BigNumber operator-(const BigNumber& x);
        BigNumber operator++(int);
        BigNumber operator--(int);

        //assignment
        BigNumber &operator=(const BigNumber& a);
        BigNumber &operator=(const int& a);
        BigNumber &operator+=(const BigNumber& a);
        BigNumber &operator-=(const BigNumber& a);
        BigNumber &operator*=(const BigNumber& a);
        BigNumber &operator/=(const BigNumber& a);

        // copy
        BigNumber copy() const;

        // get digits number
        size_t digitLen();

        // Debug methods
        uint32_t getFirstChunk();
        std::string debug();

    private:
        // binary operators
        static BigNumber add(BigNumber a, BigNumber b);
        static BigNumber sub(BigNumber a, BigNumber b);
        static BigNumber mul(BigNumber a, BigNumber b);
        static BigNumber div(BigNumber a, BigNumber b);
        BigNumber increment();
        BigNumber decrement();

        // compare operators
        static int compare(BigNumber a, BigNumber b);

        // utils
        std::string toString();
        BigNumber removeStartZeros();

        static BigNumber countPi(int accuracy);

        //TODO: everything else
};

#endif //DEMO_LIB_BIGNUMBER_H
