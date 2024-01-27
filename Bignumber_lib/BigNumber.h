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

    friend std::ostream& operator<< (std::ostream& stream, const BigNumber& matrix);
    friend BigNumber operator+(const BigNumber &, const BigNumber &);

    // Debug methods
    int getFirstChunk();

    //TODO: everything else
};

#endif //DEMO_LIB_BIGNUMBER_H
