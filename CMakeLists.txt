cmake_minimum_required(VERSION 3.20)
project(mp2_lab3_arithmetic)

set(CMAKE_CXX_STANDARD 14)

#include_directories(gtest)
include_directories(include)
include_directories(samples)
include_directories(test)

add_executable(
        mp2_lab3_arithmetic
#        gtest/gtest-all.cc
#        gtest/gtest.h
        include/arithmetic.h
        include/stack.h
#        samples/main_arithmetic.cpp
        src/arithmetic.cpp
        test/test_arithmetic.cpp
        test/test_main.cpp
        test/test_stack.cpp
)

add_subdirectory(Google_tests/lib)
include_directories(Google_tests/lib/googletest/include)
target_link_libraries(mp2_lab3_arithmetic gtest)
#add_subdirectory(Google_tests)