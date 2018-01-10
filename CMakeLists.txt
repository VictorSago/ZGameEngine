cmake_minimum_required(VERSION 3.4)

project(ZGE2d)

set(CMAKE_CXX_STANDARD 14)

add_subdirectory(ZGE2d)
add_subdirectory(zgeDemoApp)

#add_library(ZGE2d SHARED ZGE2d/src/library.cpp ZGE2d/include/ZGE2d/library.h)

message("Boost_Found 2: " ${Boost_FOUND})
message("  Boost include dirs: ${Boost_INCLUDE_DIRS}")
message("  Boost libs: ${Boost_LIBRARIES}")

get_property(inc_dirs1 DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY INCLUDE_DIRECTORIES)
get_property(appDir_inc_dirs DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/zgeDemoApp PROPERTY INCLUDE_DIRECTORIES)
get_property(libDir_inc_dirs DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/ZGE2d PROPERTY INCLUDE_DIRECTORIES)
get_property(demoApp_inc_dirs TARGET DemoApp PROPERTY INCLUDE_DIRECTORIES)
get_property(zge2dLib_inc_dirs TARGET ZGE2dLib PROPERTY INCLUDE_DIRECTORIES)
message("Include dirs1: " ${inc_dirs1})
message("Include dirs2: " ${appDir_inc_dirs})
message("Include dirs3: " ${libDir_inc_dirs})
message("DemoApp: " ${demoApp_inc_dirs})
message("ZGE2dLib: " ${zge2dLib_inc_dirs})


#add_executable(DemoApp zgeDemoApp/src/main.cpp)
#target_include_directories(DemoApp ZGE2d/include/ZGE2d)
#target_link_libraries(DemoApp ZGE2dLib)

