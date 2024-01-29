//
// Created by QUASARITY on 27.01.2024 with love.
//

#ifndef DEMO_LIB_BIGNUMBER_H
#define DEMO_LIB_BIGNUMBER_H

#include <vector>

class BigNumber {
    static const int base = 1e9;
    static const int baseLen = 9;

    std::vector<uint32_t> payload;
    int pointPosition;
    bool sign;

    public:
        // constructors and destructors
        BigNumber();
        explicit BigNumber(int x);
        explicit BigNumber(double x);
        explicit BigNumber(float x);
        explicit BigNumber(long long x);
        explicit BigNumber(std::string x);
        ~BigNumber();

        // to write
        friend std::ostream& operator<< (std::ostream& stream, const BigNumber& bigNumber);

        // to read
        friend std::istream& operator>> (std::istream& stream, BigNumber& bigNumber);

        // change the sign
        friend BigNumber operator-(const BigNumber& x);

        // sum
        friend BigNumber operator+(const BigNumber& a, const BigNumber& b);

        // diff
        friend BigNumber operator-(const BigNumber& a, const BigNumber& b);

        // mul
        friend BigNumber operator*(const BigNumber& a, const BigNumber& b);

        // div
        friend BigNumber operator/(const BigNumber& a, const BigNumber& b);

        // increment
        friend BigNumber operator++(const BigNumber& a);

        // decrement
        friend BigNumber operator--(const BigNumber& a);

        // is equals
        friend bool operator==(const BigNumber& a, const BigNumber& b);

        // is bigger than
        friend bool operator>(const BigNumber& a, const BigNumber& b);

        // is bigger or equals
        friend bool operator>=(const BigNumber& a, const BigNumber& b);

        // is lesser than
        friend bool operator<(const BigNumber& a, const BigNumber& b);

        // is lesser or equals
        friend bool operator<=(const BigNumber& a, const BigNumber& b);

        // is not equals
        friend bool operator!=(const BigNumber& a, const BigNumber& b);

        //assignment
        BigNumber &operator=(const BigNumber& bigNumber);

        // copy
        BigNumber copy() const;

        // Debug methods
        uint32_t getFirstChunk();

        std::string debug();

    private:
        // binary operators
        static BigNumber sum(BigNumber a, BigNumber b);
        static BigNumber dif(BigNumber a, BigNumber b);
        static BigNumber mul(BigNumber a, BigNumber b);
        static BigNumber div(BigNumber a, BigNumber b);
        BigNumber negate();

        // compare operators
        static int compare(BigNumber a, BigNumber b);

        // utils
        std::string toString();
        BigNumber removeStartZeros();

        static BigNumber countPi(int accuracy);

        //TODO: everything else
};

#endif //DEMO_LIB_BIGNUMBER_H
