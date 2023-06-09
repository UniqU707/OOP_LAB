cmake_minimum_required(VERSION 3.11)

project(figure CXX)

set(CMAKE_CXX_STANDARD 23)

if(MSVC)
    set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS true)
    if(CMAKE_CXX_FLAGS MATCHES "/W[0-4]")
        string(REGEX REPLACE "/W[0-4]" "/W4" CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}")
    else()
        set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /W4")
    endif()
endif()

include(FetchContent)
FetchContent_Declare(googletest URL https://github.com/google/googletest/archive/6b63c98ac43efc992122f1da12aaf0a0e0658206.zip)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)


add_library(figure SHARED 
    "include/figure/figure.h"
    "include/figure/figure_console.h"
    "src/figure.cc"
    "src/figure_list.cc"
    "src/figure_console.cc")
target_include_directories(figure PUBLIC "include")


add_executable(figure_tests  
    "tests/figure_tests.cc"
    "tests/figure_list_tests.cc")
target_link_libraries(figure_tests figure GTest::gtest_main)

add_executable(console "src/console.cc")
target_link_libraries(console figure)