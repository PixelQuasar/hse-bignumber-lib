//
// Created by QUASARITY on 22.02.2024.
//
#include "gtest/gtest.h"
#include "BigNumber.h"

// later can be changed on something like "ASSIGN"
#define OUTPUT_PREFIX "[  OUTPUT  ] "

TEST(AssignmentTestSuite, BasicAssign) {
BigNumber a = BigNumber(1);
BigNumber b = a;
BigNumber result = b;
BigNumber expected = BigNumber(1);
std::cout << OUTPUT_PREFIX << "EXPECTED: " << expected << std::endl;
std::cout << OUTPUT_PREFIX << "GOT: " << result << std::endl;
ASSERT_EQ(result, expected);
}

TEST(AssignmentTestSuite, AdditionAssign) {
    BigNumber a = BigNumber(1);
    BigNumber b = a;
    b += a;
    BigNumber result = b;
    BigNumber expected = BigNumber(2);
    std::cout << OUTPUT_PREFIX << "EXPECTED: " << expected << std::endl;
    std::cout << OUTPUT_PREFIX << "GOT: " << result << std::endl;
    ASSERT_EQ(result, expected);
}

TEST(AssignmentTestSuite, SubstractionAssign) {
    BigNumber a = BigNumber(1);
    BigNumber b = a;
    b -= a;
    BigNumber result = b;
    BigNumber expected = BigNumber(0);
    std::cout << OUTPUT_PREFIX << "EXPECTED: " << expected << std::endl;
    std::cout << OUTPUT_PREFIX << "GOT: " << result << std::endl;
    ASSERT_EQ(result, expected);
}

TEST(AssignmentTestSuite, MultiplicationAssign) {
    BigNumber a = BigNumber(1);
    BigNumber b = a;
    b *= a;
    BigNumber result = b;
    BigNumber expected = BigNumber(1);
    std::cout << OUTPUT_PREFIX << "EXPECTED: " << expected << std::endl;
    std::cout << OUTPUT_PREFIX << "GOT: " << result << std::endl;
    ASSERT_EQ(result, expected);
}

TEST(AssignmentTestSuite, DivisionAssign) {
    BigNumber a = BigNumber(1);
    BigNumber b = a;
    b *= a;
    BigNumber result = b;
    BigNumber expected = BigNumber(1);
    std::cout << OUTPUT_PREFIX << "EXPECTED: " << expected << std::endl;
    std::cout << OUTPUT_PREFIX << "GOT: " << result << std::endl;
    ASSERT_EQ(result, expected);
}
