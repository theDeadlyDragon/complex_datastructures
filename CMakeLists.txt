cmake_minimum_required(VERSION 3.0)


project(complex_datastructures VERSION 1.0)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_library(complex_datastructures SHARED library.cpp)
