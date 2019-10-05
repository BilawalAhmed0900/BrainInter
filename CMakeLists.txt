cmake_minimum_required(VERSION 3.14)
project(Brainfuck_Interpreter)

set(CMAKE_CXX_STANDARD 14)

add_executable(Brainfuck_Interpreter main.cpp interpreter.cpp interpreter.h version.h)