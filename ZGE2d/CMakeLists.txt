cmake_minimum_required(VERSION 3.4)

project(ZGE2d)

set(CMAKE_CXX_STANDARD 14)

enable_testing()

find_package(Boost OPTIONAL_COMPONENTS unit_test_framework)

add_subdirectory(ZVecLib)

#message("Boost_Found 1: " ${Boost_FOUND})
#message("  include dirs: ${Boost_INCLUDE_DIRS}")
#message("  libs: ${Boost_LIBRARIES}")

find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)
find_package(SDL2_ttf REQUIRED)

#message("SDL2_Found 2: " ${SDL2_FOUND})
#message("  include dirs: ${SDL2_INCLUDE_DIR}")
#message("  libs: ${SDL2_LIBRARY}")
#
#message("SDL2_image_Found 2: " ${SDL2_IMAGE_FOUND})
#message("  include dirs: " ${SDL2_IMAGE_INCLUDE_DIR})
#message("  libs: ${SDL2_IMAGE_LIBRARY}")
#
#message("SDL2_ttf_Found 2: ${SDL2_TTF_FOUND}")
#message("  include dirs: ${SDL2_TTF_INCLUDE_DIR}")
#message("  libs: ${SDL2_TTF_LIBRARY}")

set(ZGE2D_SRC_DIR ${CMAKE_CURRENT_LIST_DIR}/src)
set(ZGE2D_INC_DIR ${CMAKE_CURRENT_LIST_DIR}/include/${PROJECT_NAME})
include_directories(${ZGE2D_INC_DIR})

#message("CMake Current List Dir: " ${CMAKE_CURRENT_LIST_DIR})
#message("ZGE2d source (ZGE2D_SRC_DIR): " ${ZGE2D_SRC_DIR})

add_library(ZGE2dLib SHARED "")

target_sources(ZGE2dLib
        PRIVATE
            ${ZGE2D_SRC_DIR}/IEventHandler.cpp
            ${ZGE2D_SRC_DIR}/GameEngine.cpp
            ${ZGE2D_SRC_DIR}/Session.cpp
            ${ZGE2D_SRC_DIR}/GameWindow.cpp
            ${ZGE2D_SRC_DIR}/Timer.cpp
            ${ZGE2D_SRC_DIR}/Texture.cpp
            ${ZGE2D_SRC_DIR}/Entity.cpp
            ${ZGE2D_SRC_DIR}/Label.cpp
            ${ZGE2D_SRC_DIR}/Animation.cpp
            ${ZGE2D_SRC_DIR}/Sprite.cpp
            ${ZGE2D_SRC_DIR}/MovingSprite.cpp
            ${ZGE2D_SRC_DIR}/ControlledSprite.cpp
            ${ZGE2D_SRC_DIR}/SpriteGroup.cpp
            ${ZGE2D_SRC_DIR}/SpriteContainer.cpp
            ${ZGE2D_SRC_DIR}/Widget.cpp
            ${ZGE2D_SRC_DIR}/WidgetContainer.cpp
        PUBLIC
            ${ZGE2D_INC_DIR}/IEventHandler.hpp
            ${ZGE2D_INC_DIR}/Definitions.hpp
            ${ZGE2D_INC_DIR}/GameEngine.hpp
            ${ZGE2D_INC_DIR}/Session.hpp
            ${ZGE2D_INC_DIR}/GameWindow.hpp
            ${ZGE2D_INC_DIR}/Timer.hpp
            ${ZGE2D_INC_DIR}/Texture.hpp
            ${ZGE2D_INC_DIR}/Entity.hpp
            ${ZGE2D_INC_DIR}/Label.hpp
            ${ZGE2D_INC_DIR}/Animation.hpp
            ${ZGE2D_INC_DIR}/Sprite.hpp
            ${ZGE2D_INC_DIR}/MovingSprite.hpp
            ${ZGE2D_INC_DIR}/ControlledSprite.hpp
            ${ZGE2D_INC_DIR}/SpriteGroup.hpp
            ${ZGE2D_INC_DIR}/SpriteContainer.hpp
            ${ZGE2D_INC_DIR}/Widget.hpp
            ${ZGE2D_INC_DIR}/WidgetContainer.hpp
        )

target_link_libraries(ZGE2dLib ${SDL2_LIBRARY} ${SDL2_IMAGE_LIBRARY} ${SDL2_TTF_LIBRARY})

#target_compile_definitions(ZGE2dLib PUBLIC DEBUG_BUILD=1)

if(Boost_FOUND)
    # Add tests
endif()

#message("CMake Module Path 1: " ${CMAKE_MODULE_PATH})
#message("ZGE2dLib 2: " ${ZGE2dLib})
