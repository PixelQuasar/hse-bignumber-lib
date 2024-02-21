//
// Created by QUASARITY on 22.02.2024.
//
#include "gtest/gtest.h"
#include "BigNumber.h"

// later can be changed on something like "ARITHM"
#define OUTPUT_PREFIX "[  OUTPUT  ] "

// utils
std::string shorten(BigNumber x, size_t n = 100) {
    if (BigNumber::toString(x).length() <= n) {
        return BigNumber::toString(x);
    }
    else {
        return BigNumber::toString(x).substr(0, n) + "...";
    }
}


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

// multiplication
TEST(MultiplicationTestSuite, BasicMul) {
    BigNumber a = BigNumber(1);
    BigNumber b = BigNumber(1);
    BigNumber result = a * b;
    BigNumber expected = BigNumber(1);
    std::cout << OUTPUT_PREFIX << "EXPECTED: " << expected << std::endl;
    std::cout << OUTPUT_PREFIX << "AND  GOT: " << result << std::endl;
    ASSERT_EQ(result, expected);
}

TEST(MultiplicationTestSuite, BigMul) {
    BigNumber a = BigNumber("354292530528395323424329070938245032");
    BigNumber b = BigNumber("123123123123123123123123123123");
    BigNumber result = a * b;
    BigNumber expected = BigNumber("43621602857850475256448924650010571526271278653872680204479074936");
    std::cout << OUTPUT_PREFIX << "EXPECTED: " << expected << std::endl;
    std::cout << OUTPUT_PREFIX << "AND  GOT: " << result << std::endl;
    ASSERT_EQ(result, expected);
}

TEST(MultiplicationTestSuite, TinyMul) {
    BigNumber a = BigNumber("35.4292530528395323424329070938245032");
    BigNumber b = BigNumber("0.0123123123123123123123123123123");
    BigNumber result = a * b;
    BigNumber expected = BigNumber("0.43621602857850475256448924650010571526271278653872680204479074936");
    std::cout << OUTPUT_PREFIX << "EXPECTED: " << expected << std::endl;
    std::cout << OUTPUT_PREFIX << "AND  GOT: " << result << std::endl;
    ASSERT_EQ(result, expected);
}

// division!
TEST(DivisionTestSuite, BasicDiv) {
    BigNumber a = BigNumber(1);
    BigNumber b = BigNumber(1);
    BigNumber result = a / b;
    BigNumber expected = BigNumber(1);
    std::cout << OUTPUT_PREFIX << "EXPECTED: " << expected << std::endl;
    std::cout << OUTPUT_PREFIX << "AND  GOT: " << result << std::endl;
    ASSERT_EQ(result, expected);
}

TEST(DivisionTestSuite, DivOnPowerTwo) {
    BigNumber a = BigNumber("43621602857850475256448924650010571526271278653872680204479074936");
    BigNumber b = BigNumber("4096");
    BigNumber result = a / b;
    BigNumber expected = BigNumber("10649805385217401185656475744631487189031073890105634815546649.154296875");
    std::cout << OUTPUT_PREFIX << "EXPECTED: " << expected << std::endl;
    std::cout << OUTPUT_PREFIX << "AND  GOT: " << result.removeZeros() << std::endl;
    ASSERT_EQ(result, expected);
}

TEST(DivisionTestSuite, BadDivision) {
    BigNumber a = BigNumber("10649805385217401185656475744631487189031073890105634815546649.154296875");
    BigNumber b = BigNumber("1000004567811");
    BigNumber result = a / b;
    BigNumber expected = BigNumber("10649756739141420811343938058866438580265396129446.275373426089389498074667410055383007510889078678246633639566148219712934364841565998681573996320802291879762326410968034389691866387206105989689793129076357280595373766365160885788089127422814777665007619223881825341135506682480085193959570094342167792808192165018938512677453468288595563202011854655028176361");
    std::cout << OUTPUT_PREFIX << "EXPECTED: " << shorten(expected) << std::endl;
    std::cout << OUTPUT_PREFIX << "AND  GOT: " << shorten(result.removeZeros()) << std::endl;
    ASSERT_EQ(result, expected);
}

TEST(DivisionTestSuite, InsaneDivision) {
    BigNumber a = BigNumber("10649756739141420811343938058866438580265396129446.275373426089389498074667410055383007510889078678246633639566148219712934364841565998681573996320802291879762326410968034389691866387206105989689793129076357280595373766365160885788089127422814777665007619223881825341135506682480085193959570094342167792808192165018938512677453468288595563202011854655028176361");
    BigNumber b = BigNumber("0.0000000000000001343621602857850475256448924650010571526271278653872680204479074936");
    BigNumber result = a / b;
    BigNumber expected = BigNumber("79261577191745408131600484573792326474538287459764439454156803636.46194690878933815214348400581239923219300429887605015264493355887805028140591841319043115278008723002822467816054028121750794225318356728398902682684834698912240853854661485368022697223083265316155037751283717533398247434985225870599545763690450490666475828316610591178922933518974343723753918673692859112112711094395749218048220031333647600153273223784576334665467928186953193333856734588415387659411163318974010599073741410973773774391560268096288337992491863546108141262558264620457161205507034151365885080553750449614442353");
    std::cout << OUTPUT_PREFIX << "EXPECTED: " << shorten(expected) << std::endl;
    std::cout << OUTPUT_PREFIX << "AND  GOT: " << shorten(result.removeZeros()) << std::endl;
    ASSERT_EQ(result, expected);
}
