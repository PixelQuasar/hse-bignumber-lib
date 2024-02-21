//
// Created by QUASARITY on 22.02.2024.
//
#include "gtest/gtest.h"
#include "BigNumber.h"

// later can be changed on something like "UTILS"
#define OUTPUT_PREFIX "[  OUTPUT  ] "

// addition
TEST(OtherTestSuite, UnaryMinus) {
    BigNumber a = BigNumber(1.1);
    BigNumber result = -a;
    BigNumber expected = BigNumber(-1.1);
    std::cout << OUTPUT_PREFIX << "EXPECTED: " << expected << std::endl;
    std::cout << OUTPUT_PREFIX << "GOT: " << result << std::endl;
    ASSERT_EQ(result, expected);
}

TEST(OtherTestSuite, MathAbs) {
    BigNumber a = BigNumber(-1.1);
    BigNumber result = a.abs();
    BigNumber expected = BigNumber(1.1);
    std::cout << OUTPUT_PREFIX << "EXPECTED: " << expected << std::endl;
    std::cout << OUTPUT_PREFIX << "GOT: " << result << std::endl;
    ASSERT_EQ(result, expected);
}

TEST(OtherTestSuite, toString) {
    BigNumber a = BigNumber("-1234234.1231231231231");
    std::string result = BigNumber::toString(a);
    std::string expected = "-1234234.1231231231231";
    std::cout << OUTPUT_PREFIX << "EXPECTED: " << expected << std::endl;
    std::cout << OUTPUT_PREFIX << "GOT: " << result << std::endl;
    ASSERT_EQ(result, expected);
}
