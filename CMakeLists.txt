cmake_minimum_required(VERSION 3.25)
project(cpp_util)

set(CMAKE_CXX_STANDARD 14)

include_directories(utils)

add_executable(cpp_util
        utils/sort.cpp
        utils/sort.hpp
        main.cpp)
