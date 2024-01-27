//
// Created by QUASARITY on 27.01.2024.
//
#include "gtest/gtest.h"
#include "BigNumber.h"


TEST(AbsoluteDateTestSuite, ExampleNumber) { // 12/2/2020 -> 737761
    BigNumber bigNumber = BigNumber(123);

    ASSERT_EQ(bigNumber.getFirstChunk(), 123);
}
