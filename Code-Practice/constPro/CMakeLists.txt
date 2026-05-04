cmake_minimum_required(VERSION 4.2)
project(constPro)

set(CMAKE_CXX_STANDARD 17)

add_executable(constPro main.cpp
        global.h
        global.cpp)
