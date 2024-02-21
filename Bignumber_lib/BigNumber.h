//
// Created by QUASARITY on 27.01.2024 with love.
//

#ifndef DEMO_LIB_BIGNUMBER_H
#define DEMO_LIB_BIGNUMBER_H

#include <vector>

class BigNumber {
        static const int base = 1e9;
        static const int baseLen = 9;
        static const int _precision = 300;

        int pointPosition;
        bool sign;
        std::vector<uint32_t> payload;

    public:
        // constructors and destructors
        BigNumber();

        explicit BigNumber(int x);
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
        BigNumber operator++(int);
        BigNumber operator--(int);

        //assignment
        BigNumber& operator=(const BigNumber &a);
        BigNumber& operator=(const int &a);
        BigNumber& operator+=(const BigNumber &b);
        BigNumber& operator-=(const BigNumber &b);
        BigNumber& operator*=(const BigNumber &b);
        BigNumber& operator/=(const BigNumber &b);

        // abs
        BigNumber abs() const;

        // get digits number
        size_t digitLen();

        // Debug methods
        uint32_t getFirstChunk();
        std::string debug() const;

    private:
        explicit BigNumber(size_t n, uint32_t x);
        explicit BigNumber(std::vector<u_int32_t> newPayload, bool newSign, int newPointPosition);

        // binary operators
        static BigNumber add(const BigNumber a, const BigNumber b, bool reduceZeros = true);
        static BigNumber sub(const BigNumber a, const BigNumber b, bool reduceZeros = true);
        static BigNumber mul(const BigNumber a, const BigNumber b, bool reduceZeros = true);
        static BigNumber div(const BigNumber a, const BigNumber b, bool reduceZeros = true, size_t precision = _precision);

    public: // TODO: remove on prod
        BigNumber removeZeros();

        // compare operators
        static int compare(const BigNumber &a, const BigNumber &b);

        // utils
        bool isZero() const;
        BigNumber removeStartZeros();
        static void swap(BigNumber &a, BigNumber &b);
        static BigNumber countPi(int accuracy);
        //TODO: everything else
};

BigNumber operator "" _bign(const char *x, size_t size);
BigNumber operator "" _bign(long double x);
BigNumber operator "" _bign(unsigned long long x);

#endif //DEMO_LIB_BIGNUMBER_H
