//
// Created by QUASARITY on 27.01.2024.
//
#include "gtest/gtest.h"
#include "BigNumber.h"
#include <iostream>


TEST(AbsoluteDateTestSuite, ExampleNumber) {
    BigNumber bigNumber = BigNumber(123);

    ASSERT_EQ(bigNumber.getFirstChunk(), 123);
}

TEST(TinyDivisionTest, HandlesDivision) {
    EXPECT_EQ(BigNumber(10) / BigNumber(3), BigNumber(3));
}

TEST(SmallDivisionTest, HandlesDivision) {
    EXPECT_EQ(BigNumber(100) / BigNumber(3), BigNumber(33));
}

TEST(CommonDivisionTest, HandlesDivision) {
    EXPECT_EQ(BigNumber(1000) / BigNumber(3), BigNumber(333));
}

TEST(BigDivisionTest, HandlesDivision) {
    EXPECT_EQ(BigNumber(100000000) / BigNumber(3), BigNumber(3333333));
}



TEST(LargeDivisionTest, HandlesDivision) {
    EXPECT_EQ(BigNumber("10000000000") / BigNumber(3), BigNumber("333333333333"));
}
