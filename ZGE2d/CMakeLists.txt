cmake_minimum_required(VERSION 3.4)

project(ZGE2d)

set(CMAKE_CXX_STANDARD 14)

enable_testing()

find_package(Boost OPTIONAL_COMPONENTS unit_test_framework)

message("Boost_Found 1: " ${Boost_FOUND})
message("  include dirs: ${Boost_INCLUDE_DIRS}")
message("  libs: ${Boost_LIBRARIES}")

find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)

#message("SDL2_Found 2: " ${SDL2_FOUND})
#message("  include dirs: ${SDL2_INCLUDE_DIR}")
#message("  libs: ${SDL2_LIBRARY}")
#
#message("SDL2_image_Found 2: " ${SDL2_IMAGE_FOUND})
#message("  include dirs: ${SDL2_IMAGE_INCLUDE_DIR}")
#message("  libs: ${SDL2_IMAGE_LIBRARY}")

set(ZGE2D_SRC_DIR ${CMAKE_CURRENT_LIST_DIR}/src)
set(ZGE2D_INC_DIR ${CMAKE_CURRENT_LIST_DIR}/include/${PROJECT_NAME})
include_directories(${ZGE2D_INC_DIR})

#message("CMake Current List Dir: " ${CMAKE_CURRENT_LIST_DIR})
#message("ZGE2d source (ZGE2D_SRC_DIR): " ${ZGE2D_SRC_DIR})

add_library(ZGE2dLib SHARED "")

target_sources(ZGE2dLib
        PRIVATE
            ${ZGE2D_SRC_DIR}/GameEngine.cpp
            ${ZGE2D_SRC_DIR}/Session.cpp
            ${ZGE2D_SRC_DIR}/VisComp.cpp
            ${ZGE2D_SRC_DIR}/Texture.cpp
            ${ZGE2D_SRC_DIR}/Label.cpp
        PUBLIC
            ${ZGE2D_INC_DIR}/GameEngine.hpp
            ${ZGE2D_INC_DIR}/Session.hpp
            ${ZGE2D_INC_DIR}/VisComp.hpp
            ${ZGE2D_INC_DIR}/Texture.hpp
            ${ZGE2D_INC_DIR}/Label.hpp
        )

if (Boost_FOUND)
    # Add tests
endif ()

#message("CMake Module Path 1: " ${CMAKE_MODULE_PATH})
message("ZGE2dLib 2: " ${ZGE2dLib})
