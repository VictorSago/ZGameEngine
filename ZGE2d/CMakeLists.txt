cmake_minimum_required(VERSION 3.4)

project(ZGE2d)

set(CMAKE_CXX_STANDARD 14)

enable_testing()

find_package(Boost OPTIONAL_COMPONENTS unit_test_framework)

message("Boost_Found 1: " ${Boost_FOUND})
message("  Boost include dirs: ${Boost_INCLUDE_DIRS}")
message("  Boost libs: ${Boost_LIBRARIES}")

find_package(SDL2 REQUIRED)

message("SDL2_Found 2: " ${SDL2_FOUND})
message("  SDL2 include dirs: ${SDL2_INCLUDE_DIR}")
message("  SDL2 libs: ${SDL2_LIBRARY}")

include_directories(${CMAKE_CURRENT_LIST_DIR}/include/${PROJECT_NAME})

add_library(ZGE2dLib SHARED "")

target_sources(ZGE2dLib
        PRIVATE
            ${CMAKE_CURRENT_LIST_DIR}/src/library.cpp
        PUBLIC
            ${CMAKE_CURRENT_LIST_DIR}/include/${PROJECT_NAME}/library.h
        )

if (Boost_FOUND)
    # Add tests
endif ()

message("CMake Module Path 1: " ${CMAKE_MODULE_PATH})
