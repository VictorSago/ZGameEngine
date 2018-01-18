cmake_minimum_required(VERSION 3.4)

project(zgeDemoApp)

set(CMAKE_CXX_STANDARD 14)

include_directories(include)
include_directories(../ZGE2d/include)

#message("ZGE2dLib_Src: " ${ZGE2dLib_SOURCE_DIR})
#message("ZGE2dLib_Include: " ${ZGE2dLib_INCLUDE_DIR})

#message("CMake Module Path 2a: " ${CMAKE_MODULE_PATH})
#message("SDL2_Found 3: " ${SDL2_FOUND})
#message("  SDL2 include dirs: ${SDL2_INCLUDE_DIR}")
#message("  SDL2 libs: ${SDL2_LIBRARY}")

add_executable(DemoApp src/main.cpp)

target_link_libraries(DemoApp ZGE2dLib ${SDL2_LIBRARY})

#target_compile_definitions(DemoApp PUBLIC DEBUG_BUILD=1)

message("ZGE2dLib 1: " ${ZGE2dLib})
