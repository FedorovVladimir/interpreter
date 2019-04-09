cmake_minimum_required(VERSION 3.13)
project(interpreter)

set(CMAKE_CXX_STANDARD 14)

add_executable(interpreter src/code/main.cpp src/code/scanner/scaner.h src/code/scanner/scaner.cpp src/code/scanner/defs.h)