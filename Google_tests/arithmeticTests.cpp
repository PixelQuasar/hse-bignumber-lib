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
    std::cout << OUTPUT_PREFIX << "AND  GOT: " << shorten(result) << std::endl;
    ASSERT_EQ(result, expected);
}

TEST(DivisionTestSuite, BadDivision) {
    BigNumber a = BigNumber("10649805385217401185656475744631487189031073890105634815546649.154296875");
    BigNumber b = BigNumber("1000004567811");
    BigNumber result = a / b;
    BigNumber expected = BigNumber("10649756739141420811343938058866438580265396129446.2753734260893894980746674100553830075108890786782466336395661482197129343648415659986815739963208022918797623264109680343896918663872061059896897931290763572805953737663651608857880891274228147776650076192238818253411355066824800");
    std::cout << OUTPUT_PREFIX << "EXPECTED: " << shorten(expected) << std::endl;
    std::cout << OUTPUT_PREFIX << "AND  GOT: " << shorten(result) << std::endl;
    ASSERT_EQ(result, expected);
}

TEST(DivisionTestSuite, InsaneDivision) {
    BigNumber a = BigNumber("10649756739141420811343938058866438580265396129446.275373426089389498074667410055383007510889078678246633639566148219712934364841565998681573996320802291879762326410968034389691866387206105989689793129076357280595373766365160885788089127422814777665007619223881825341135506682480085193959570094342167792808192165018938512677453468288595563202011854655028176361");
    BigNumber b = BigNumber("0.0000000000000001343621602857850475256448924650010571526271278653872680204479074936");
    BigNumber result = a / b;
    BigNumber expected = BigNumber("79261577191745408131600484573792326474538287459764439454156803636.461946908789338152143484005812399232193004298876050152644933558878050281405918413190431152780087230028224678160540281217507942253183567283989026826848346989122408538546614853680226972230832653161550377512837175333982474349852258705995457636904504906664758283166105911789229335189743437237539186736928591121127110943957492180482200313336476001532732237845763346654679281869531933338567345884153876594111633189740105990737414109737737743915602680962");
    std::cout << OUTPUT_PREFIX << "EXPECTED: " << shorten(expected) << std::endl;
    std::cout << OUTPUT_PREFIX << "AND  GOT: " << shorten(result) << std::endl;
    ASSERT_EQ(result, expected);
}

TEST(DivisionTestSuite, DivideByZero) {
    EXPECT_THROW({
        BigNumber a = BigNumber(1);
        BigNumber b = BigNumber(0);
        BigNumber result = a / b;
        FAIL() << "Error expected :(";
    }, std::invalid_argument);
}
