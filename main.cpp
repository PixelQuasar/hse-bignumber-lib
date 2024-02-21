//
// Created by QUASARITY on 27.01.2024.
//
#include <iostream>
#include <chrono>
#include "BigNumber.h"

int main() {
//    BigNumber a = BigNumber("300");
//    BigNumber b = BigNumber("1");
//    std::cout << a / b << std::endl;
    //std::cout << "600000"_bign - "3000"_bign << std::endl;

//    std::cout << (BigNumber::div(
//    BigNumber("1"),
//    BigNumber("0.31830988618379067153776752674502872406891759116361898279897755762296472268498260131542292654820140462639666740182678026494756495477012877181109084712983560087950259086701451438558226419254141526266650987039344"),
//    false, 1000)) << std::endl;
    //std::cout << "1"_bign / "0.3183098861837911373460803921473266286049957980270750250950776289072593910943783612963555695946895744"_bign;

    std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();

    BigNumber::countPi(10);
    std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
    std::cout << "REAL: " << "3.14159265358979323846264338327950288419716939937510582097494459230781640628620899862803482534211706798214" << std::endl;

    std::cout << "Time difference (sec) = " <<  (std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count()) /1000000.0  <<std::endl;
    //std::cout << "600000000000000"_bign / "3"_bign << std::endl;
////

    //BigNumber k = BigNumber(2);
//    BigNumber mult = "4"_bign / ("8"_bign * k + "1"_bign)
//    - "2"_bign / ("8"_bign * k + "4"_bign)
//    - "1"_bign / ("8"_bign * k + "5"_bign)
//    - "1"_bign / ("8"_bign * k + "6"_bign)
//    ;
    //std::cout << "1"_bign / "10"_bign << std::endl;
    //std::cout << mult << std::endl;
    //std::cout << ("12121.00012120000"_bign).removeZeros() << std::endl;
    //std::cout << "2"_bign / "4"_bign << std::endl;
    //std::cout << ("1"_bign / ("8"_bign * k + "5"_bign)).debug() << std::endl;
    //std::cout << (mult - "1"_bign / ("8"_bign * k + "5"_bign)).debug() << std::endl;

    //BigNumber badNumber = BigNumber("1968749999999656250");
    // 22499999998.750
    // 18750000000.625

    //std::cout << (BigNumber("22499999999.75") - BigNumber("1")) << std::endl;
    //std::cout << (BigNumber("20039062498.66796875") - BigNumber("19921875000.6640625")).debug() << std::endl;
    //std::cout << BigNumber("500000002015624999998.6718750") - BigNumber("1968750000000.656250") << std::endl;
    //std::cout << BigNumber("1968749999999.656250") + BigNumber(1) << std::endl;
    //std::cout << (badNumber + BigNumber("1000000")).debug() << std::endl;
    //std::cout << badNumber.debug() << std::endl;
//    std::cout << a + b << std::endl; // 6 + 3 = 9
//    std::cout << (-a) + b << std::endl; // -6 + 3 = -3
//    std::cout << a + (-b) << std::endl; // 6 - 3 = 3
//    std::cout << (-a) + (-b) << std::endl; // -6 + -3 = -9
//    std::cout << a - b << std::endl; // 6 - 3 = 3
//    std::cout << b - a << std::endl; // 3 - 6 = -3
//    std::cout << (-a) - b << std::endl; // -6 - 3 = -9
//    std::cout << a - (-b) << std::endl; // 6 - -3 = 9
//    BigNumber c = a / b;
    //BigNumber c = a / b;
    //std::cout << "A: " << a.debug() << std::endl << "B: " << b.debug() << std::endl << "C: " << c.debug() << std::endl;

    return 0;
}
