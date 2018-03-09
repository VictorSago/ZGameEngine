cmake_minimum_required(VERSION 3.4)

project(ZVecLib)

set(CMAKE_CXX_STANDARD 14)

enable_testing()

find_package(Boost OPTIONAL_COMPONENTS unit_test_framework)

set(ZVECLIB_SRC_DIR ${CMAKE_CURRENT_LIST_DIR}/src)
set(ZVECLIB_INC_DIR ${CMAKE_CURRENT_LIST_DIR}/include/${PROJECT_NAME})
include_directories(${ZVECLIB_INC_DIR})

include_directories(${Boost_INCLUDE_DIR})
#include_directories("${gtest_SOURCE_DIR}/include")

#message("ZVecLib CMake Current List Dir: " ${CMAKE_CURRENT_LIST_DIR})
#message("ZVecLib source (ZVECLIB_SRC_DIR): " ${ZVECLIB_SRC_DIR})
#message("ZVecLib include (ZVECLIB_INC_DIR): " ${ZVECLIB_INC_DIR})

add_library(ZVecLib SHARED "")

target_sources(ZVecLib
        PRIVATE
            ${ZVECLIB_INC_DIR}/Common.hpp
            ${ZVECLIB_SRC_DIR}/Vec2dRec.cpp
        PUBLIC
            ${ZVECLIB_INC_DIR}/Vec2dRec.hpp
        )

if(Boost_FOUND)
    add_executable(ZVecLibTest
            tests/Vec2dRec_test1.cpp
            tests/Vec2dRec_test2.cpp
            tests/Vec2dRec_test3.cpp
            )
    target_include_directories(ZVecLibTest PRIVATE ${Boost_INCLUDE_DIRS})
    target_compile_definitions(ZVecLibTest PRIVATE "BOOST_TEST_DYN_LINK=1")
    target_link_libraries(ZVecLibTest ZVecLib ${Boost_LIBRARIES})
    add_test(NAME VecTests1 COMMAND ZVecLibTest --show_progress=yes)
endif()

set(my_gtest_sources
        tests/Vec2dRecGTest1.cpp
        tests/VectorTransformationGTest.cpp
        tests/VectorTransformationGTest.hpp tests/VectorOperatorGTest.hpp tests/VectorOperatorGTest.cpp tests/VectorOperationsGTest.cpp tests/VectorOperationsGTest.hpp)

# Now simply link against gtest or gtest_main as needed. Eg
add_executable(ZVecLibGTestMain ${my_gtest_sources})
target_link_libraries(ZVecLibGTestMain ZVecLib gtest_main)
add_test(NAME VecGTestMain COMMAND ZVecLibGTestMain)

# Now simply link against gtest or gtest_main as needed. Eg
add_executable(ZVecLibGTest ${my_gtest_sources} tests/main.cpp)
target_link_libraries(ZVecLibGTest ZVecLib gtest)
add_test(NAME VecGTest COMMAND ZVecLibGTest)

message("gtest_SOURCE_DIR: " ${gtest_SOURCE_DIR})
message("ZVecLib_INCLUDE: " ${ZVecLib_INCLUDE})
message("CMAKE_BINARY_DIR in ZVecLib ${CMAKE_BINARY_DIR}")
#message("GTest Found: " ${gtest_FOUND})
