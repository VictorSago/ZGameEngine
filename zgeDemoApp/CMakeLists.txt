cmake_minimum_required(VERSION 3.4)

project(zgeDemoApp)

set(CMAKE_CXX_STANDARD 14)

include_directories(include)
include_directories(../ZGE2d/include)

message("ZGE2dLib_Src: " ${ZGE2dLib_SOURCE_DIR})
message("ZGE2dLib_Include: " ${ZGE2dLib_INCLUDE_DIR})

add_executable(DemoApp src/main.cpp)

target_link_libraries(DemoApp ZGE2dLib)
