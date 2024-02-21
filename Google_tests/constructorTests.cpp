//
// Created by QUASARITY on 22.02.2024.
//
#include "gtest/gtest.h"
#include "BigNumber.h"

// later can be changed on something like "CONSTR"
#define OUTPUT_PREFIX "[  OUTPUT  ] "

TEST(ConstructorTestSuite, FromString) {
    BigNumber a = BigNumber("-1123123132132132132132.1112122212121212");
    std::string result = BigNumber::toString(a);
    std::string expected = "-1123123132132132132132.1112122212121212";
    std::cout << OUTPUT_PREFIX << "EXPECTED: " << expected << std::endl;
    std::cout << OUTPUT_PREFIX << "GOT: " << result << std::endl;
    ASSERT_EQ(result, expected);
}

TEST(ConstructorTestSuite, FromInt) {
    BigNumber a = BigNumber(234234);
    std::string result = BigNumber::toString(a);
    std::string expected = std::to_string(234234);
    std::cout << OUTPUT_PREFIX << "EXPECTED: " << expected << std::endl;
    std::cout << OUTPUT_PREFIX << "GOT: " << result << std::endl;
    ASSERT_EQ(result, expected);
}

TEST(ConstructorTestSuite, FromDouble) {
    BigNumber a = BigNumber(-234.234);
    std::string result = BigNumber::toString(a);
    std::string expected = std::to_string(-234.234);
    std::cout << OUTPUT_PREFIX << "EXPECTED: " << expected << std::endl;
    std::cout << OUTPUT_PREFIX << "GOT: " << result << std::endl;
    ASSERT_EQ(result, expected);
}

TEST(ConstructorTestSuite, FromLongLong) {
    BigNumber a = BigNumber(234234234234234);
    std::string result = BigNumber::toString(a);
    std::string expected = std::to_string(234234234234234);
    std::cout << OUTPUT_PREFIX << "EXPECTED: " << expected << std::endl;
    std::cout << OUTPUT_PREFIX << "GOT: " << result << std::endl;
    ASSERT_EQ(result, expected);
}

TEST(ConstructorTestSuite, Copy) {
    BigNumber a = BigNumber("777");
    BigNumber b = a;
    std::string result = BigNumber::toString(b);
    std::string expected = "777";
    std::cout << OUTPUT_PREFIX << "EXPECTED: " << expected << std::endl;
    std::cout << OUTPUT_PREFIX << "GOT: " << result << std::endl;
    ASSERT_EQ(result, expected);
}
