cmake_minimum_required(VERSION 3.4)

project(ZGameEngine2d)

set(CMAKE_CXX_STANDARD 14)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${PROJECT_SOURCE_DIR}/cmake)

#message("SDL2_Found 1: " ${SDL2_FOUND})
#message("  include dirs: ${SDL2_INCLUDE_DIR}")
#message("  libs: ${SDL2_LIBRARY}")

# Download and unpack googletest at configure time
configure_file(${CMAKE_MODULE_PATH}/GTest.cmake.in googletest-download/CMakeLists.txt)
execute_process(COMMAND ${CMAKE_COMMAND} -G "${CMAKE_GENERATOR}" .
        RESULT_VARIABLE result
        WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/googletest-download )
if(result)
    message(FATAL_ERROR "CMake step for googletest failed: ${result}")
endif()
execute_process(COMMAND ${CMAKE_COMMAND} --build .
        RESULT_VARIABLE result
        WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/googletest-download )
if(result)
    message(FATAL_ERROR "Build step for googletest failed: ${result}")
endif()

# Prevent overriding the parent project's compiler/linker settings on Windows
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

# Add googletest directly to our build. This defines the gtest and gtest_main targets.
add_subdirectory(
        ${CMAKE_BINARY_DIR}/googletest-src
        ${CMAKE_BINARY_DIR}/googletest-build
        EXCLUDE_FROM_ALL
        )

# The gtest/gtest_main targets carry header search path dependencies automatically
# when using CMake 2.8.11 or later. Otherwise we have to add them here ourselves.
#if (CMAKE_VERSION VERSION_LESS 2.8.11)
    include_directories("${gtest_SOURCE_DIR}/include")
#endif()

add_subdirectory(ZGE2d)
add_subdirectory(zgeDemoApp)

#message("CMake Module Path 0: " ${CMAKE_MODULE_PATH})

#message("Boost_Found 2: " ${Boost_FOUND})
#message("  include dirs: ${Boost_INCLUDE_DIR}")
#message("  libs: ${Boost_LIBRARIES}")

get_property(inc_dirs1 DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY INCLUDE_DIRECTORIES)
get_property(appDir_inc_dirs DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/zgeDemoApp PROPERTY INCLUDE_DIRECTORIES)
get_property(libDir_inc_dirs DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/ZGE2d PROPERTY INCLUDE_DIRECTORIES)
get_property(ZVecLibDir_inc_dirs DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/ZGE2d/ZVecLib PROPERTY INCLUDE_DIRECTORIES)
get_property(demoApp_inc_dirs TARGET DemoApp PROPERTY INCLUDE_DIRECTORIES)
get_property(zge2dLib_inc_dirs TARGET ZGE2dLib PROPERTY INCLUDE_DIRECTORIES)
get_property(zVecLib_inc_dirs TARGET ZVecLib PROPERTY INCLUDE_DIRECTORIES)
message("Include dirs1: " ${inc_dirs1})
message("appDir_inc_dirs: " ${appDir_inc_dirs})
message("libDir_inc_dirs: " ${libDir_inc_dirs})
message("ZVecLibDir_inc_dirs: " ${ZVecLibDir_inc_dirs})
message("DemoApp_inc_dirs: " ${demoApp_inc_dirs})
message("ZGE2dLib_inc_dirs: " ${zge2dLib_inc_dirs})
message("zVecLib_inc_dirs: " ${zVecLib_inc_dirs})
message("CMAKE_BINARY_DIR ${CMAKE_BINARY_DIR}")

# Now simply link against gtest or gtest_main as needed. Eg
#add_executable(example example.cpp)
#target_link_libraries(example gtest_main)
#add_test(NAME example_test COMMAND example)
