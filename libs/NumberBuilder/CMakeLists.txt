cmake_minimum_required(VERSION 3.26)

set(CMAKE_CXX_STANDARD "20")

project(NumberBuilder)
add_library(NumberBuilder SHARED numberbuilder.cpp inc/numberbuilder.hpp)
target_include_directories(NumberBuilder PUBLIC inc)
