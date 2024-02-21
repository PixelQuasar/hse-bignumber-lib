//
// Created by QUASARITY on 22.02.2024.
//
#include "gtest/gtest.h"
#include "BigNumber.h"

// later can be changed on something like "COMPARE"
#define OUTPUT_PREFIX "[  OUTPUT  ] "

TEST(ComparisonTestSuite, BasicCompare) {
BigNumber a = BigNumber(1);
BigNumber b = BigNumber(1);
bool result = a == b;
bool expected = true;
std::cout << OUTPUT_PREFIX << "EXPECTED: " << expected << std::endl;
std::cout << OUTPUT_PREFIX << "GOT: " << result << std::endl;
ASSERT_EQ(result, expected);
}

TEST(ComparisonTestSuite, NonTrivialCompare) {
    BigNumber a = BigNumber("0.000000000000000123000");
    BigNumber b = BigNumber("0.000000000000000123");
    bool result = a != b;
    bool expected = false;
    std::cout << OUTPUT_PREFIX << "EXPECTED: " << expected << std::endl;
    std::cout << OUTPUT_PREFIX << "GOT: " << result << std::endl;
    ASSERT_EQ(result, expected);
}

TEST(ComparisonTestSuite, BasicNotEquals) {
    BigNumber a = BigNumber(1);
    BigNumber b = BigNumber(1);
    bool result = a != b;
    bool expected = false;
    std::cout << OUTPUT_PREFIX << "EXPECTED: " << expected << std::endl;
    std::cout << OUTPUT_PREFIX << "GOT: " << result << std::endl;
    ASSERT_EQ(result, expected);
}

TEST(ComparisonTestSuite, GreaterThan) {
    BigNumber a = BigNumber("10");
    BigNumber b = BigNumber("20");
    bool result = a > b;
    bool expected = false;
    std::cout << OUTPUT_PREFIX << "EXPECTED: " << expected << std::endl;
    std::cout << OUTPUT_PREFIX << "GOT: " << result << std::endl;
    ASSERT_EQ(result, expected);
}

TEST(ComparisonTestSuite, LesserThan) {
    BigNumber a = BigNumber("10");
    BigNumber b = BigNumber("20");
    bool result = a < b;
    bool expected = true;
    std::cout << OUTPUT_PREFIX << "EXPECTED: " << expected << std::endl;
    std::cout << OUTPUT_PREFIX << "GOT: " << result << std::endl;
    ASSERT_EQ(result, expected);
}

TEST(ComparisonTestSuite, GreaterOrEquals) {
    BigNumber a = BigNumber("20");
    BigNumber b = BigNumber("20");
    bool result = a >= b;
    bool expected = true;
    std::cout << OUTPUT_PREFIX << "EXPECTED: " << expected << std::endl;
    std::cout << OUTPUT_PREFIX << "GOT: " << result << std::endl;
    ASSERT_EQ(result, expected);
}

TEST(ComparisonTestSuite, LesserOrEquals) {
    BigNumber a = BigNumber("10");
    BigNumber b = BigNumber("20");
    bool result = a <= b;
    bool expected = true;
    std::cout << OUTPUT_PREFIX << "EXPECTED: " << expected << std::endl;
    std::cout << OUTPUT_PREFIX << "GOT: " << result << std::endl;
    ASSERT_EQ(result, expected);
}
