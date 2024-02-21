project(Bignumber)

set(HEADER_FILES
    BigNumber.h)

set(SOURCE_FILES
    BigNumber.cpp
        utils/trim.cpp
        utils/completeWithZeros.cpp
        BigNumber/arithmetics/add.cpp
        BigNumber/arithmetics/sub.cpp
        BigNumber/arithmetics/mul.cpp
        BigNumber/arithmetics/div.cpp
        BigNumber/countPi.cpp
        BigNumber/compare.cpp
)

add_library(Bignumber_lib STATIC ${SOURCE_FILES} ${HEADER_FILES})