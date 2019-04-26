cmake_minimum_required(VERSION 3.13)
project(interpreter)

set(CMAKE_CXX_STANDARD 14)

add_executable(interpreter src/code/main.cpp src/code/scanner/Sanner.h src/code/scanner/Sanner.cpp src/code/scanner/TypeLexeme.h src/code/scanner/Node.cpp src/code/scanner/Node.h src/code/lexer/Lexer.cpp src/code/lexer/Lexer.h src/code/tree/Tree.cpp src/code/tree/Tree.h)
