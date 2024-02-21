//
// Created by QUASARITY on 22.02.2024.
//
#include "gtest/gtest.h"
#include "BigNumber.h"

// later can be changed on something like "ARITHM"
#define OUTPUT_PREFIX "[  OUTPUT  ] "

// addition
TEST(AdditionTestSuite, BasicAdd) {
    BigNumber a = BigNumber(1);
    BigNumber b = BigNumber(1);
    BigNumber result = a + b;
    BigNumber expected = BigNumber(2);
    std::cout << OUTPUT_PREFIX << "EXPECTED: " << expected << std::endl;
    std::cout << OUTPUT_PREFIX << "GOT: " << result << std::endl;
    ASSERT_EQ(result, expected);
}

TEST(AdditionTestSuite, BigAdd) {
    BigNumber a = BigNumber("123123123123123123123123123123");
    BigNumber b = BigNumber("354292530528395323424329070938245032");
    BigNumber result = a + b;
    BigNumber expected = BigNumber("354292653651518446547452194061368155");
    std::cout << OUTPUT_PREFIX << "EXPECTED: " << expected << std::endl;
    std::cout << OUTPUT_PREFIX << "AND  GOT: " << result << std::endl;
    ASSERT_EQ(result, expected);
}

TEST(AdditionTestSuite, TinyAdd) {
    BigNumber a = BigNumber("12.3123123123123123123123123123");
    BigNumber b = BigNumber("354292.530528395323424329070938245032");
    BigNumber result = a + b;
    BigNumber expected = BigNumber("354304.842840707635736641383250557332");
    std::cout << OUTPUT_PREFIX << "EXPECTED: " << expected << std::endl;
    std::cout << OUTPUT_PREFIX << "AND  GOT: " << result << std::endl;
    ASSERT_EQ(result, expected);
}

TEST(AdditionTestSuite, TransitionToSub) {
    BigNumber a = BigNumber("123123123123123123123123123123");
    BigNumber b = BigNumber("-354292530528395323424329070938245032");
    BigNumber result = a + b;
    BigNumber expected = BigNumber("-354292407405272200301205947815121909");
    std::cout << OUTPUT_PREFIX << "EXPECTED: " << expected << std::endl;
    std::cout << OUTPUT_PREFIX << "AND  GOT: " << result << std::endl;
    ASSERT_EQ(result, expected);
}

// substraction
TEST(SubstractionTestSuite, BasicSub) {
    BigNumber a = BigNumber(1);
    BigNumber b = BigNumber(1);
    BigNumber result = a - b;
    BigNumber expected = BigNumber(0);
    std::cout << OUTPUT_PREFIX << "EXPECTED: " << expected << std::endl;
    std::cout << OUTPUT_PREFIX << "AND  GOT: " << result << std::endl;
    ASSERT_EQ(result, expected);
}

TEST(SubstractionTestSuite, BigSub) {
    BigNumber a = BigNumber("354292530528395323424329070938245032");
    BigNumber b = BigNumber("123123123123123123123123123123");
    BigNumber result = a - b;
    BigNumber expected = BigNumber("354292407405272200301205947815121909");
    std::cout << OUTPUT_PREFIX << "EXPECTED: " << expected << std::endl;
    std::cout << OUTPUT_PREFIX << "AND  GOT: " << result << std::endl;
    ASSERT_EQ(result, expected);
}

TEST(SubstractionTestSuite, TinySub) {
    BigNumber a = BigNumber("12.3123123123123123123123123123");
    BigNumber b = BigNumber("354292.530528395323424329070938245032");
    BigNumber result = a - b;
    BigNumber expected = BigNumber("-354280.218216083011112016758625932732");
    std::cout << OUTPUT_PREFIX << "EXPECTED: " << expected << std::endl;
    std::cout << OUTPUT_PREFIX << "AND  GOT: " << result << std::endl;
    ASSERT_EQ(result, expected);
}

TEST(SubstractionTestSuite, TransitionToSub) {
    BigNumber a = BigNumber("123123123123123123123123123123");
    BigNumber b = BigNumber("-354292530528395323424329070938245032");
    BigNumber result = a - b;
    BigNumber expected = BigNumber("354292653651518446547452194061368155");
    std::cout << OUTPUT_PREFIX << "EXPECTED: " << expected << std::endl;
    std::cout << OUTPUT_PREFIX << "AND  GOT: " << result << std::endl;
    ASSERT_EQ(result, expected);
}

