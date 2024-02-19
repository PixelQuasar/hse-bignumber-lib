//
// Created by QUASARITY on 27.01.2024 with love.
//

#ifndef DEMO_LIB_BIGNUMBER_H
#define DEMO_LIB_BIGNUMBER_H

#include <vector>

class BigNumber {
        static const int base = 1e9;
        static const int baseLen = 9;
        static const int divisionAccuracy = baseLen * 2;

        int pointPosition;
        bool sign;
        std::vector<uint32_t> payload;

    public:
        // constructors and destructors
        BigNumber();

        explicit BigNumber(int x);
        explicit BigNumber(double x);
        explicit BigNumber(float x);
        explicit BigNumber(long long x);
        explicit BigNumber(std::string x);
        BigNumber(BigNumber& x);
        BigNumber(const BigNumber& x);
        ~BigNumber();

        friend std::ostream &operator<<(std::ostream &stream, const BigNumber &bigNumber);
        friend std::istream &operator>>(std::istream &stream, BigNumber &bigNumber);

        // binary
        friend BigNumber operator+(const BigNumber &a, const BigNumber &b);
        friend BigNumber operator-(const BigNumber &a, const BigNumber &b);
        friend BigNumber operator*(const BigNumber &a, const BigNumber &b);
        friend BigNumber operator/(const BigNumber &a, const BigNumber &b);
        friend bool operator==(const BigNumber &a, const int &b);
        friend bool operator>(const BigNumber &a, const int &b);
        friend bool operator>=(const BigNumber &a, const int &b);
        friend bool operator<(const BigNumber &a, const int &b);
        friend bool operator<=(const BigNumber &a, const int &b);
        friend bool operator!=(const BigNumber &a, const int &b);
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


        // copy
        BigNumber copy() const;

        // get digits number
        size_t digitLen();

        // Debug methods
        uint32_t getFirstChunk();
        std::string debug();

    private:
        explicit BigNumber(size_t n, uint32_t x);
        explicit BigNumber(std::vector<u_int32_t> newPayload, bool newSign, int newPointPosition);

        // binary operators
        static BigNumber add(BigNumber a, BigNumber b);
        static BigNumber sub(BigNumber a, BigNumber b);
        static BigNumber mul(BigNumber a, BigNumber b);
        static BigNumber div(BigNumber a, BigNumber b);

        BigNumber increment();
        BigNumber decrement();

    public: // TODO: remove on prod
        BigNumber removeZeros();
        BigNumber shift(size_t numberOfZeros);

        // compare operators
        static int compare(const BigNumber &a, const BigNumber &b);

        // utils
        //std::string toString(bool point = true);
        static std::string toString(const BigNumber& bigNumber, bool point = true);
        BigNumber removeStartZeros();
        static void swap(BigNumber &a, BigNumber &b);
        static BigNumber countPi(int accuracy);
        //TODO: everything else
};

BigNumber operator "" _bign(const char *x, size_t size);


#endif //DEMO_LIB_BIGNUMBER_H
