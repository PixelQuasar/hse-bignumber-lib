//
// Created by QUASARITY on 30.01.2024.
//
#include "BigNumber.h"
#include <iostream>

BigNumber BigNumber::div(const BigNumber a, const BigNumber b) {
    if (b == 1)
        return a;

    if (b == -1)
        return -a;

    // Declaring and Initialising
    // the variables.
    BigNumber low = BigNumber(0);
    BigNumber high = a.abs();
    BigNumber mid;

    // To store the Quotient.
    BigNumber quotient = BigNumber(0);

    size_t limitIndex = 0;

    while (low <= high && limitIndex < 10) {
        // Calculating mid.
        //std::cout << " > " << mid.pointPosition << std::endl;
        mid = low + (high - low) * BigNumber("0.5");
        std::cout << low << " + (" << high << " - " << low << ") * 0.5 = " << mid << std::endl;
        //std::cout << " > " << mid.pointPosition << std::endl;
        // To search in lower bound.
        if ((mid * b).abs() > a.abs()) {
            //std::cout << " > " << mid.pointPosition << std::endl;
            high = mid - BigNumber(1);
            //std::cout << " > " << mid.pointPosition << std::endl;

            // To search in upper bound.
        }
        else {
            quotient = mid;
            low = mid + BigNumber(1);
            //std::cout << " > " << mid.pointPosition << std::endl;
        }
        limitIndex += 1;
        std::cout << "(" << quotient << ") " << mid << " " << (mid * b).abs() << " " << a.abs() << " " << ((mid * b).abs() > a.abs()) << std::endl;
    }

    // Checking the parity and
    // returning the Quotient.
    if ((a < 0 && b < 0 || a > 0 && b > 0)) {
        return quotient;
    }
    else {
        return -quotient;
    }
}
