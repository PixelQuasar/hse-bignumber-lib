project(Bignumber)

set(HEADER_FILES
    BigNumber.h)

set(SOURCE_FILES
    BigNumber.cpp
        utils/trim.cpp)

add_library(Bignumber_lib STATIC ${SOURCE_FILES} ${HEADER_FILES})