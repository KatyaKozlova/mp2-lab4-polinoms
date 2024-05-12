cmake_minimum_required(VERSION 3.5)
project(polinom)

include_directories(${CMAKE_SOURCE_DIR}/polinoms)
include_directories(${CMAKE_SOURCE_DIR}/gtest)

add_executable(test test/test_main.cpp test/test_list.cpp test/test_polinom.cpp)
add_executable(sample sample/main.cpp)

set(GTEST gtest/gtest.h gtest/gtest-all.cc)
set(POLINOM polinoms/Polinom.cpp polinoms/Polinom.h polinoms/List.h)

add_library(gtest STATIC ${GTEST})
add_library(polinoms STATIC ${POLINOM})

target_link_libraries(test gtest polinoms)
target_link_libraries(sample polinoms)
