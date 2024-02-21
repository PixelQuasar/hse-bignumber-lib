#include <iostream>
#include "BigNumber.h"

BigNumber pow(BigNumber a, size_t n) {
    BigNumber result = BigNumber(1);
    for (int i = 0; i < n; i++) {
        result *= a;
    }
    return result;
}

BigNumber BigNumber::countPi(int accuracy) {
    BigNumber result = BigNumber(0);
    BigNumber kFactorialInPowerOf3 = BigNumber(1);
    BigNumber k3Factorial = BigNumber(1);
    BigNumber k6Factorial = BigNumber(1);
    BigNumber MAGIC_NUMBER_ONE = "13591409"_bign;
    BigNumber MAGIC_NUMBER_TWO = "545140134"_bign;
    BigNumber MAGIC_NUMBER_THREE = "640320"_bign;
    std::string MAGIC_NUMBER_FOUR_RAW = "512384047.99600074981255466992791529927985060803010899361005608614623126188949113059562159893746802321614884";
    BigNumber MAGIC_NUMBER_FOUR = BigNumber(
            MAGIC_NUMBER_FOUR_RAW.substr(0,
                                         std::max(12, std::min(accuracy + 12, static_cast<int>(MAGIC_NUMBER_FOUR_RAW.length())))));

    for (int k = 0; k < std::max(10, accuracy / 10); k++) {
        if (k != 0) {
            kFactorialInPowerOf3 *= BigNumber(k * k * k);
            for (int j = 0; j < 6; j++) {
                k6Factorial *= BigNumber(k * 6 - j);
            }
            for (int j = 0; j < 3; j++) {
                k3Factorial *= BigNumber(k * 3 - j);
            }
        }
        BigNumber mult = BigNumber(
                k6Factorial * (MAGIC_NUMBER_ONE + MAGIC_NUMBER_TWO * BigNumber(k)) /
                ((k3Factorial) * kFactorialInPowerOf3 * pow(MAGIC_NUMBER_THREE, 3 * k) * MAGIC_NUMBER_FOUR)
        );
        mult.sign = (k & 1);
        result += mult;
    }
    result = result * "12"_bign;
    result = BigNumber(BigNumber::toString(result).substr(0, accuracy + 5));
    result = BigNumber::div("1"_bign, result, false, accuracy * 10);

    return BigNumber(BigNumber::toString(result).substr(0, accuracy + 2));
}
