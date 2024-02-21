cmake_minimum_required(VERSION 3.26)
project(hse_bignumber_lib)

set(CMAKE_CXX_STANDARD 17)

set(SOURCE_FILES main.cpp)
add_executable(Bignumber_run ${SOURCE_FILES})

include_directories(Bignumber_lib)
add_subdirectory(Bignumber_lib)

target_link_libraries(Bignumber_run Bignumber_lib)

add_subdirectory(Google_tests)

# tests!
add_executable(cMakeTest main.cpp)
target_link_libraries(cMakeTest PRIVATE Bignumber_lib)

# enable testing functionality
enable_testing()

# define tests
add_test(
        NAME cMakeTest
        COMMAND $<TARGET_FILE:cMakeTest>
)
