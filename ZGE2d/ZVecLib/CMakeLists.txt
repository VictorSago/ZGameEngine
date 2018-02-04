cmake_minimum_required(VERSION 3.4)

project(ZVecLib)

set(CMAKE_CXX_STANDARD 14)

enable_testing()

find_package(Boost OPTIONAL_COMPONENTS unit_test_framework)

set(ZVECLIB_SRC_DIR ${CMAKE_CURRENT_LIST_DIR}/src)
set(ZVECLIB_INC_DIR ${CMAKE_CURRENT_LIST_DIR}/include/${PROJECT_NAME})
include_directories(${ZVECLIB_INC_DIR})

include_directories(${Boost_INCLUDE_DIR})

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
    add_test(NAME VecTests1 COMMAND ZVecLibTest)
endif()

message("Boost_INCLUDE_DIR: ${Boost_INCLUDE_DIR}")
message("Boost_INCLUDE_DIRS: ${Boost_INCLUDE_DIRS}")
message("Boost_LIBRARIES: ${Boost_LIBRARIES}")
