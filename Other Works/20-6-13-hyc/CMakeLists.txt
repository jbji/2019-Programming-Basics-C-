cmake_minimum_required(VERSION 3.15)
project(20_6_13_hyc)

set(CMAKE_CXX_STANDARD 14)

add_executable(20_6_13_hyc main.cpp)

set(CMAKE_EXE_LINKER_FLAGS "-static-libgcc -static-libstdc++")