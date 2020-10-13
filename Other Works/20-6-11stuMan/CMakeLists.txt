cmake_minimum_required(VERSION 3.15)
project(20_6_11stuMan)

set(CMAKE_CXX_STANDARD 14)

add_executable(20_6_11stuMan main.cpp Course.cpp Course.h Student.cpp Student.h IO.cpp IO.h Score.cpp Score.h IdGenerator.cpp IdGenerator.h)

set(CMAKE_EXE_LINKER_FLAGS "-static-libgcc -static-libstdc++")
