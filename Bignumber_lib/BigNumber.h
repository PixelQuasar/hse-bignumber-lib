//
// Created by QUASARITY on 27.01.2024 with love.
//

#ifndef DEMO_LIB_BIGNUMBER_H
#define DEMO_LIB_BIGNUMBER_H

#include <vector>

class BigNumber {
    static const int base = 1e9;
    static const int baseLen = 9;

    std::vector<int> payload;
    int pointPosition;
    bool sign;

    public:
        BigNumber();
        BigNumber(int x);
        BigNumber(double x);
        BigNumber(float x);
        BigNumber(long long x);
        ~BigNumber();

        // to write
        friend std::ostream& operator<< (std::ostream& stream, const BigNumber& matrix);

        // to read
        friend BigNumber operator>> (std::ostream& stream, const BigNumber& matrix);

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

        // Debug methods
        int getFirstChunk();

    private:
        // binary operators
        BigNumber sum(BigNumber a, BigNumber b);
        BigNumber dif(BigNumber a, BigNumber b);
        BigNumber mul(BigNumber a, BigNumber b);
        BigNumber div(BigNumber a, BigNumber b);

        // compare operators
        bool compare(BigNumber a, BigNumber b);

        // utils
        std::string toString();

        static BigNumber countPi(int accuracy);

        //TODO: everything else
};

#endif //DEMO_LIB_BIGNUMBER_H
