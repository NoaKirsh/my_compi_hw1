cmake_minimum_required(VERSION 3.7)
project(compi_hw1)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp part_a.cpp part_b.cpp scanner_hw1.lex tokens.hpp lex.yy.c)
add_executable(compi_hw1 ${SOURCE_FILES})