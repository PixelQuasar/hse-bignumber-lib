//
// Created by QUASARITY on 27.01.2024.
//

#ifndef DEMO_LIB_BIGNUMBER_H
#define DEMO_LIB_BIGNUMBER_H

#include <vector>
#include <iostream>

class BigNumber {
    public:
        // constructors and destructors
        BigNumber();

        explicit BigNumber(int x);
        explicit BigNumber(long double x);
        explicit BigNumber(double x);
        explicit BigNumber(long x);
        explicit BigNumber(std::string x);
        BigNumber(BigNumber& x);
        BigNumber(const BigNumber& x);
        ~BigNumber();

        friend std::ostream &operator<<(std::ostream &stream, const BigNumber &bigNumber);
        friend std::istream &operator>>(std::istream &stream, BigNumber &bigNumber);

        static std::string toString(const BigNumber& bigNumber, bool point = true);

        // binary
        friend BigNumber operator+(const BigNumber &a, const BigNumber &b);
        friend BigNumber operator-(const BigNumber &a, const BigNumber &b);
        friend BigNumber operator*(const BigNumber &a, const BigNumber &b);
        friend BigNumber operator/(const BigNumber &a, const BigNumber &b);

        friend bool operator==(const BigNumber &a, const BigNumber &b);
        friend bool operator>(const BigNumber &a, const BigNumber &b);
        friend bool operator>=(const BigNumber &a, const BigNumber &b);
        friend bool operator<(const BigNumber &a, const BigNumber &b);
        friend bool operator<=(const BigNumber &a, const BigNumber &b);
        friend bool operator!=(const BigNumber &a, const BigNumber &b);

        // unary
        friend BigNumber operator-(const BigNumber &x);

        //assignment
        BigNumber& operator=(const BigNumber &a);
        BigNumber& operator=(const int &a);
        BigNumber& operator+=(const BigNumber &b);
        BigNumber& operator-=(const BigNumber &b);
        BigNumber& operator*=(const BigNumber &b);
        BigNumber& operator/=(const BigNumber &b);

        // abs
        BigNumber abs() const;

        // Debug methods
        std::string debug() const;

        static BigNumber countPi(int accuracy);
    private:
        static const int base = 1e9;
        static const int baseLen = 9;
        static const int defaultPrecision = 220;

        int pointPosition;
        bool sign;
        std::vector<uint32_t> payload;

        explicit BigNumber(size_t n, uint32_t x);
        explicit BigNumber(std::vector<u_int32_t> newPayload, bool newSign, int newPointPosition);

        // binary operators
        static BigNumber add(const BigNumber& a, const BigNumber& b, bool reduceZeros = true);
        static BigNumber sub(const BigNumber& a, const BigNumber& b, bool reduceZeros = true);
        static BigNumber mul(const BigNumber& a, const BigNumber& b, bool reduceZeros = true);
        static BigNumber div(const BigNumber& a, const BigNumber& b, bool reduceZeros = true, size_t precision = defaultPrecision);

        BigNumber removeZeros();

        // compare operators
        static int compare(const BigNumber &a, const BigNumber &b);

        // utils
        bool isZero() const;
        static void swap(BigNumber &a, BigNumber &b);
};

BigNumber operator "" _bign(const char *x, size_t size);
BigNumber operator "" _bign(long double x);
BigNumber operator "" _bign(unsigned long long x);

#endif //DEMO_LIB_BIGNUMBER_H
