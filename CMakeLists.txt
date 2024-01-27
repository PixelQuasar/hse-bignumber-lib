cmake_minimum_required(VERSION 3.26)
project(hse_bignumber_lib)

set(CMAKE_CXX_STANDARD 17)

set(SOURCE_FILES main.cpp)
add_executable(Bignumber_run ${SOURCE_FILES})

include_directories(Bignumber_lib)
add_subdirectory(Bignumber_lib)

target_link_libraries(Bignumber_run Bignumber_lib)

add_subdirectory(Google_tests)
