cmake_minimum_required(VERSION 3.26)
project(hse_bignumber_lib)

set(CMAKE_CXX_STANDARD 17)

add_library(hse_bignumber_lib library.cpp
        BigNumber.cpp
        BigNumber.h)
